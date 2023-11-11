#pragma once

#include <list>
#include "Certificate.h"

class Cryptoprovider {
protected:
    std::list<Certificate*> mCertificates;
    std::list<Certificate*>::iterator mCertificatesIterator;
    
    // ��������� ������ ������������
    // ���� ������ �� ����, �������� ������
    virtual void refillCertificates() = 0;

public:
    Cryptoprovider();

    Certificate* GetFirstCertificate();
    Certificate* GetNextCertificate();

    virtual ~Cryptoprovider() = default;
};

