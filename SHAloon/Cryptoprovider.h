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
    
    // Пересканирование сертификатов
    // Если список не пуст, очистить список
    virtual void refillCertificates() = 0;

public:
    Cryptoprovider();

    bool IsInitialized();

    // Вызов этого метода подразумевает пересканирование сертификатов, поскольку
    // предполагается, что список сертификатов всегда должен быть актуальным
    Certificate* GetFirstCertificate();

    // Возвращает следующий сертификат из итератора
    // или nullptr, если достигнут конец списка
    Certificate* GetNextCertificate();

    virtual void SignDocument(Certificate* certificate, 
        const std::string& absoluteFilePath, const std::string& absoluteSignaturePath) = 0;

    virtual ~Cryptoprovider();
};

