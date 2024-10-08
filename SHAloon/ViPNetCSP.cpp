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
    // �����, ���� �� ��� ���������������� ����� ��� ���� �����������������
    auto cspNames = getAllCSPNames();
    auto thisName = _T(VPN_DEF_PROV_2012_512_A);

    for (auto& name : cspNames) {
        if (name == thisName) {
            mInitialized = true;
            Logger::Log(true, _T("ViPNetCSP::ViPNetCSP()"), _T("Successfully initiated"), tstring(), LogLevel::LOG_INFO);
        }
    }
}

void ViPNetCSP::SignDocument(Certificate* certificate,
                             LPCTSTR absoluteFilePath, 
                             LPCTSTR absoluteSignaturePath) {
    tstring logSource = _T("ViPNetCSP::SignDocument()");

    std::vector<BYTE> bData, bSignData;

    if (!getFileData(absoluteFilePath, bData)) {
        return;
    }

    DWORD dwDataSize = static_cast<DWORD>(bData.size());

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
        Logger::WinApiLog(false, logSource, _T("Error calling CryptSignMessage() for 1st time"), LogLevel::LOG_ERROR);
        return;
    }
    
    bSignData.resize(dwSignatureSize);
    BYTE* pcbSignData = bSignData.data();

    if (!CryptSignMessage(&stSignMessagePara, TRUE, 1, &pcbMessage, &dwDataSize, pcbSignData, &dwSignatureSize)) {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptSignMessage() for 2nd time"), LogLevel::LOG_ERROR);
        return;
    }

    if (!saveDataToFile(absoluteSignaturePath, bSignData)) {
        return;
    }

    Logger::Log(true, logSource, _T("Successfully signed the document"), tstring(), LogLevel::LOG_INFO);
}

Certificate* ViPNetCSP::VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) {
    tstring logSource = _T("ViPNetCSP::VerifySignature()");

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

    const BYTE* pbMessage = bFileData.data(),
              * pbSignature = bSignatureData.data();

    DWORD dwMessageSize = static_cast<DWORD>(bFileData.size()),
          dwSignatureSize = static_cast<DWORD>(bSignatureData.size());

    PCCERT_CONTEXT pcCertContext = NULL;

    if (!CryptVerifyDetachedMessageSignature(&verifyParam, 0, pbSignature, dwSignatureSize,
                                             1, &pbMessage, &dwMessageSize, &pcCertContext)) {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptVerifyDetachedMessageSignature()"), LogLevel::LOG_ERROR);
        return nullptr;
    }

    verificationCertificate = new Certificate(pcCertContext);

    CertFreeCertificateContext(pcCertContext);

    Logger::Log(true, logSource, _T("Successfully verified document signature"), tstring(), LogLevel::LOG_INFO);

    return verificationCertificate;
}

void ViPNetCSP::EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath) {
    tstring logSource = _T("ViPNetCSP::EncryptDocument()");

    std::vector<BYTE> bFileData, bEncryptedFileData;

    if (!getFileData(absoluteSourcePath, bFileData)) {
        return;
    }

    CRYPT_ENCRYPT_MESSAGE_PARA encryptParam;
    ZeroMemory(&encryptParam, sizeof(encryptParam));
    encryptParam.cbSize = sizeof(encryptParam);
    encryptParam.dwMsgEncodingType = CertificateStorage::CertificateEncodingType;
    encryptParam.ContentEncryptionAlgorithm.pszObjId = (LPSTR)szOID_CPCSP_ENCRYPT_ALG; // GOST 28147-89

    DWORD dwEncryptedFileDataSize = 0;
    DWORD dwFileDataSize = (DWORD)bFileData.size();
    const BYTE* pcbFileData = bFileData.data();
    PCCERT_CONTEXT certContext = certificate->GetCertContext();

    if (!CryptEncryptMessage(&encryptParam, 1, &certContext, pcbFileData, dwFileDataSize,
        NULL, &dwEncryptedFileDataSize))
    {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptEncryptMessage() for 1st time"), LogLevel::LOG_ERROR);
        return;
    }

    bEncryptedFileData.resize(dwEncryptedFileDataSize);

    if (!CryptEncryptMessage(&encryptParam, 1, &certContext, pcbFileData, dwFileDataSize,
        bEncryptedFileData.data(), &dwEncryptedFileDataSize))
    {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptEncryptMessage() for 2nd time"), LogLevel::LOG_ERROR);
        return;
    }

    if (!saveDataToFile(absoluteEncryptedPath, bEncryptedFileData)) {
        return;
    }

    Logger::Log(true, logSource, _T("Successfully encrypted the document"), tstring(), LogLevel::LOG_INFO);
}

Certificate* ViPNetCSP::DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath) {
    tstring logSource = _T("ViPNetCSP::DecryptDocument()");

    if (decryptionCertificate) {
        delete decryptionCertificate;
        decryptionCertificate = nullptr;
    }

    std::vector<BYTE> bEncryptedFileData, bDecryptedFileData;

    if (!getFileData(absoluteEncryptedPath, bEncryptedFileData)) {
        return nullptr;
    }

    HCERTSTORE hCertStore = CertOpenSystemStore(NULL, _T("MY"));

    if (!hCertStore) {
        Logger::WinApiLog(false, logSource, _T("Error opening certificate store"), LogLevel::LOG_ERROR);
        return nullptr;
    }

    DWORD dwEncryptedFileDataSize = (DWORD)bEncryptedFileData.size();
    DWORD dwDecryptedFileDataSize = 0;
    const BYTE* pcbEncryptedFileData = bEncryptedFileData.data();

    CRYPT_DECRYPT_MESSAGE_PARA decryptParam;
    ZeroMemory(&decryptParam, sizeof(decryptParam));
    decryptParam.cbSize = sizeof(decryptParam);
    decryptParam.dwMsgAndCertEncodingType = CertificateStorage::CertificateEncodingType;
    decryptParam.cCertStore = 1;
    decryptParam.rghCertStore = &hCertStore;

    if (!CryptDecryptMessage(&decryptParam, pcbEncryptedFileData, dwEncryptedFileDataSize,
        NULL, &dwDecryptedFileDataSize, NULL))
    {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptDecryptMessage() for 1st time"), LogLevel::LOG_ERROR);
        return nullptr;
    }

    PCCERT_CONTEXT pcCertContext = NULL;
    bDecryptedFileData.resize(dwDecryptedFileDataSize);

    if (!CryptDecryptMessage(&decryptParam, pcbEncryptedFileData, dwEncryptedFileDataSize,
        bDecryptedFileData.data(), &dwDecryptedFileDataSize, &pcCertContext))
    {
        Logger::WinApiLog(false, logSource, _T("Error calling CryptDecryptMessage() for 2nd time"), LogLevel::LOG_ERROR);
        return nullptr;
    }

    bDecryptedFileData.resize(dwDecryptedFileDataSize);

    decryptionCertificate = new Certificate(pcCertContext);
    decryptionCertificate->FreeCertificateContext();

    CertFreeCertificateContext(pcCertContext);

    if (!CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG)) {
        Logger::WinApiLog(false, logSource, _T("Error closing certificate store"), LogLevel::LOG_ERROR);
    }

    if (!saveDataToFile(absoluteDecryptedPath, bDecryptedFileData)) {
        return nullptr;
    }

    Logger::Log(true, logSource, _T("Successfully decrypted the document"), tstring(), LogLevel::LOG_INFO);

    return decryptionCertificate;
}

ViPNetCSP::~ViPNetCSP() {

}