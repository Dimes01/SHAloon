#pragma once

#include "Certificate.h"
#include <iostream>
#include <wincrypt.h>
#include <tchar.h>
#include <list>

class Cryptoprovider {
protected:
    bool mInitialized = false;

    HCRYPTPROV mHCryptProv = 0;

    std::list<Certificate*> mCertificates;
    std::list<Certificate*>::iterator mCertificatesIterator;
    
    // ���������������� ������������
    // ���� ������ �� ����, �������� ������
    virtual void refillCertificates() = 0;

public:
    Cryptoprovider();

    bool IsInitialized();

    // ����� ����� ������ ������������� ���������������� ������������, ���������
    // ��������������, ��� ������ ������������ ������ ������ ���� ����������
    Certificate* GetFirstCertificate();

    // ���������� ��������� ���������� �� ���������
    // ��� nullptr, ���� ��������� ����� ������
    Certificate* GetNextCertificate();

    virtual void SignDocument(Certificate* certificate, 
        const std::string& absoluteFilePath, const std::string& absoluteSignaturePath) = 0;

    virtual ~Cryptoprovider();
};

