#include "pch.h"
#include "ViPNetCSP.h"

LPSTR ViPNetCSP::getHashOidByKeyOid(LPSTR szKeyOid) {
    LPSTR hash1994, hash256, hash512, sign2001, sign256, sign512;

    hash1994 = const_cast<LPSTR>(szOID_CPCSP_HASH_ALG);
    hash256 = const_cast<LPSTR>(szOID_CSP2012_HASH_256);
    hash512 = const_cast<LPSTR>(szOID_CSP2012_HASH_512);
    sign2001 = const_cast<LPSTR>(szOID_DOMEN_ELIP_SIGN_ALG);
    sign256 = const_cast<LPSTR>(szOID_CSP2012_SIGN_256);
    sign512 = const_cast<LPSTR>(szOID_CSP2012_SIGN_512);
    
    if (strcmp(szKeyOid, sign2001) == 0) return hash1994;
    else if (strcmp(szKeyOid, sign256) == 0) return hash256;
    else if (strcmp(szKeyOid, sign512) == 0) return hash512;

    return NULL;
}

ViPNetCSP::ViPNetCSP() : Cryptoprovider() {
    // Пытаемся получить контекст ViPNet CSP. Если удачно, значит, он есть в системе.
    auto result = CryptAcquireContext(&hCryptProv, NULL, VPN_DEF_PROV, VPN_PROV_TYPE, CRYPT_VERIFYCONTEXT);
    if (result) {
        mInitialized = true;
    }
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
    }
}

void ViPNetCSP::SignDocument(Certificate* certificate,
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

    HCRYPTPROV hCryptProv = 0;
    DWORD dwKeySpec = 0;
    BOOL freeProv = FALSE;

    if (!CryptSignMessage(&stSignMessagePara, TRUE, 1, &pcbMessage, &dwDataSize, NULL, &dwSignatureSize)) {
        Logger::WinApiLog(false, TEXT("ViPNetCSP::SignDocument()"),
                                 TEXT("Error calling CryptSignMessage() for 1st time"),
                                 LogLevel::LOG_ERROR);
        return;
    }
    
    bSignData.resize(dwSignatureSize);
    BYTE* pcbSignData = bSignData.data();

    if (!CryptSignMessage(&stSignMessagePara, TRUE, 1, &pcbMessage, &dwDataSize, pcbSignData, &dwSignatureSize)) {
        Logger::WinApiLog(false, TEXT("ViPNetCSP::SignDocument()"),
                                 TEXT("Error calling CryptSignMessage() for 2nd time"),
                                 LogLevel::LOG_ERROR);
        return;
    }

    if (!saveDataToFile(absoluteSignaturePath, bSignData)) {
        return;
    }
}

Certificate* ViPNetCSP::VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) {
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
    DWORD dwMessageSize = (DWORD)bFileData.size(), dwSignatureSize = (DWORD)bSignatureData.size();
    PCCERT_CONTEXT pcCertContext = NULL;

    if (!CryptVerifyDetachedMessageSignature(&verifyParam, 0, pbSignature, dwSignatureSize,
                                             1, &pbMessage, &dwMessageSize, &pcCertContext)) {
        Logger::WinApiLog(false, TEXT("ViPNetCSP::VerifySignature()"),
                                 TEXT("Error calling CryptVerifyDetachedMessageSignature()"),
                                 LogLevel::LOG_ERROR);
        return nullptr;
    }

    verificationCertificate = new Certificate(pcCertContext);

    CertFreeCertificateContext(pcCertContext);

    return verificationCertificate;
}

ViPNetCSP::~ViPNetCSP() {

}