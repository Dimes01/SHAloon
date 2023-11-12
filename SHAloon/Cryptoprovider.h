#pragma once

#include <list>
#include "Certificate.h"

class Cryptoprovider {
protected:
    std::list<Certificate*> mCertificates;
    std::list<Certificate*>::iterator mCertificatesIterator;
    
    // ���������������� ������������
    // ���� ������ �� ����, �������� ������
    virtual void refillCertificates() = 0;

public:
    Cryptoprovider();

    // ����� ����� ������ ������������� ���������������� ������������, ���������
    // ��������������, ��� ������ ������������ ������ ������ ���� ����������
    Certificate* GetFirstCertificate();

    // ���������� ��������� ���������� �� ���������
    // ��� nullptr, ���� ��������� ����� ������
    Certificate* GetNextCertificate();

    virtual ~Cryptoprovider();
};

