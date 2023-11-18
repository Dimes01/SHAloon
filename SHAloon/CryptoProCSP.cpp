#include "pch.h"
#include "CryptoProCSP.h"

LPSTR CryptoProCSP::getHashOidByKeyOid(LPSTR szKeyOid) {
    LPSTR hash1994, hash256, hash512, sign2001, sign256, sign512;

    hash1994 = const_cast<LPSTR>(szOID_CP_GOST_R3411);
    hash256 = const_cast<LPSTR>(szOID_CP_GOST_R3411_12_256);
    hash512 = const_cast<LPSTR>(szOID_CP_GOST_R3411_12_512);
    sign2001 = const_cast<LPSTR>(szOID_CP_GOST_R3411);
    sign256 = const_cast<LPSTR>(szOID_CP_GOST_R3410_12_256);
    sign512 = const_cast<LPSTR>(szOID_CP_GOST_R3410_12_512);

    if (strcmp(szKeyOid, sign2001) == 0) return hash1994;
    if (strcmp(szKeyOid, sign256) == 0) return hash256;
    else if (strcmp(szKeyOid, hash512) == 0) return sign512;

    return NULL;
}

CryptoProCSP::CryptoProCSP() : Cryptoprovider() {
    // Пытаемся получить контекст КриптоПро CSP. Если удачно, значит, он есть в системе.
    auto result = CryptAcquireContext(&hCryptProv, NULL, CP_GR3410_2012_PROV, PROV_GOST_2012_256, CRYPT_VERIFYCONTEXT);
    if (result) {
        mInitialized = true;
    }
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
    }
}

void CryptoProCSP::SignDocument(Certificate* certificate,
                                LPCTSTR absoluteFilePath,
                                LPCTSTR absoluteSignaturePath) {
    std::vector<BYTE> bData, bSignData;

    if (!getFileData(absoluteFilePath, bData)) {
        return;
    }

    DWORD dwDataSize = bData.size();

    CRYPT_SIGN_MESSAGE_PARA stSignMessagePara;

    PCCERT_CONTEXT pcCertContext = certificate->GetCertContext();
    LPSTR keyOid = pcCertContext->pCertInfo->SubjectPublicKeyInfo.Algorithm.pszObjId;
    LPSTR hashOid = getHashOidByKeyOid(keyOid);

    ZeroMemory(&stSignMessagePara, sizeof(CRYPT_SIGN_MESSAGE_PARA));
    stSignMessagePara.cbSize = sizeof(CRYPT_SIGN_MESSAGE_PARA);
    stSignMessagePara.dwMsgEncodingType = CertificateStorage::CertificateEncodingType;
    stSignMessagePara.pSigningCert = pcCertContext;
    stSignMessagePara.HashAlgorithm.pszObjId = hashOid;
    stSignMessagePara.rgpMsgCert = &pcCertContext;
    stSignMessagePara.cMsgCert = 1;

    const BYTE* pcbMessage = bData.data();
    DWORD dwSignatureSize = 0;

    if (!CryptSignMessage(&stSignMessagePara, TRUE, 1, &pcbMessage, &dwDataSize, NULL, &dwSignatureSize)) {
        tstringstream errorCode;
        errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
        Logger::Log(false, TEXT("CryptoProCSP::SignDocument()"),
            TEXT("Error calling CryptSignMessage() for 1st time"),
            errorCode.str(), LogLevel::LOG_ERROR);
        return;
    }

    bSignData.resize(dwSignatureSize);
    BYTE* pcbSignData = bSignData.data();

    if (!CryptSignMessage(&stSignMessagePara, TRUE, 1, &pcbMessage, &dwDataSize, pcbSignData, &dwSignatureSize)) {
        tstringstream errorCode;
        errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
        Logger::Log(false, TEXT("CryptoProCSP::SignDocument()"),
            TEXT("Error calling CryptSignMessage() for 2nd time"),
            errorCode.str(), LogLevel::LOG_ERROR);
        return;
    }

    if (!saveDataToFile(absoluteSignaturePath, bSignData)) {
        return;
    }
}

Certificate* CryptoProCSP::VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) {
    if (verificationCertificate) {
        delete verificationCertificate;
        verificationCertificate = nullptr;
    }

    std::vector<BYTE> bFileData, bSignatureData;

    if (!getFileData(absoluteFilePath, bFileData)) {
        return nullptr;
    }

    if (!getFileData(absoluteSignaturePath, bSignatureData)) {
        return nullptr;
    }

    CRYPT_VERIFY_MESSAGE_PARA verifyParam;
    ZeroMemory(&verifyParam, sizeof(verifyParam));
    verifyParam.cbSize = sizeof(verifyParam);
    verifyParam.dwMsgAndCertEncodingType = CertificateStorage::CertificateEncodingType;

    const BYTE* pbMessage = bFileData.data(), * pbSignature = bSignatureData.data();
    DWORD pbMessageSize = (DWORD)bFileData.size(), pbSignatureSize = (DWORD)bSignatureData.size();
    PCCERT_CONTEXT pcCertContext = NULL;

    if (!CryptVerifyDetachedMessageSignature(&verifyParam, 0, pbSignature, pbSignatureSize,
                                             1, &pbMessage, &pbMessageSize, &pcCertContext)) {
        tstringstream errorCode;
        errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
        Logger::Log(false, TEXT("CryptoProCSP::VerifySignature()"),
            TEXT("Error calling CryptVerifyDetachedMessageSignature()"),
            errorCode.str(), LogLevel::LOG_ERROR);
        return nullptr;
    }

    verificationCertificate = new Certificate(pcCertContext);

    CertFreeCertificateContext(pcCertContext);

    return verificationCertificate;
}

CryptoProCSP::~CryptoProCSP() {

}
