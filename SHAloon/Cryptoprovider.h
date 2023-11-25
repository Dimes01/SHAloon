#pragma once

#include "CertificateStorage.h"
#include "Certificate.h"
#include "Logger.h"

class Cryptoprovider {
protected:
    bool mInitialized = false;

    HCRYPTPROV hCryptProv = NULL;
    Certificate* verificationCertificate = nullptr;
    Certificate* decryptionCertificate = nullptr;

    std::vector<tstring> getAllCSPNames();

    // ������� ��� ����� ����� � ��������� ��������� � ������. ������ ����������.
    bool getFileData(LPCTSTR szFile, std::vector<BYTE>& bData);

    // ��������� ������ ������ � ���� � ��������� ���������. ������ ����������.
    bool saveDataToFile(LPCTSTR szFile, const std::vector<BYTE>& bData);

    virtual LPSTR getHashOidByKeyOid(LPSTR szKeyOid) = 0;

public:
    Cryptoprovider();

    bool IsInitialized();

    virtual void SignDocument(Certificate* certificate, LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) = 0;

    virtual Certificate* VerifySignature(LPCTSTR absoluteFilePath, LPCTSTR absoluteSignaturePath) = 0;

    virtual void EncryptDocument(Certificate* certificate, LPCTSTR absoluteSourcePath, LPCTSTR absoluteEncryptedPath) = 0;

    virtual Certificate* DecryptDocument(LPCTSTR absoluteEncryptedPath, LPCTSTR absoluteDecryptedPath) = 0;

    virtual ~Cryptoprovider();
};

