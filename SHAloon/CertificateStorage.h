#pragma once
#include <string>
#include <list>
#include <sstream>
#include <wincrypt.h>
#include "Certificate.h"

class CertificateStorage {
private:
	HCERTSTORE hMemoryStore;
	PCCERT_CONTEXT pDesiredCert = NULL;	// Установить в NULL для первого обращения к функции CertFindCertificateInStore

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// Пересканирование сертификатов
	// Если список не пуст, очистить список
	virtual void refillCertificates() = 0;

	void CertFindFirstInMemoryStorage();
	void MakeCertificateInfo(PCERT_INFO pDesiredCertInfo);

public:
	CertificateStorage();
	// Вызов этого метода подразумевает пересканирование сертификатов, поскольку
	// предполагается, что список сертификатов всегда должен быть актуальным
	Certificate* CertGetFirst();

	// Возвращает следующий сертификат из итератора
	// или nullptr, если достигнут конец списка
	Certificate* GetNextCertificate();
	~CertificateStorage();
};

