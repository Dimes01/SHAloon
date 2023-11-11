#pragma once

#include <list>
#include "Certificate.h"

class Cryptoprovider {
protected:
    std::list<Certificate*> mCertificates;
    std::list<Certificate*>::iterator mCertificatesIterator;
    
    // Пересканирование сертификатов
    // Если список не пуст, очистить список
    virtual void refillCertificates() = 0;

public:
    Cryptoprovider();

    // Вызов этого метода подразумевает пересканирование сертификатов, поскольку
    // предполагается, что список сертификатов всегда должен быть актуальным
    Certificate* GetFirstCertificate();

    // Возвращает следующий сертификат из итератора
    // или nullptr, если достигнут конец списка
    Certificate* GetNextCertificate();

    virtual ~Cryptoprovider();
};

