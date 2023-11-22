#pragma once

#include "Certificate.h"
#include "ShaloonUtils.h"
#include "Logger.h"


class CertificateStorage {
private:
	HCERTSTORE hCertStore = NULL;

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// Пересканирование сертификатов
	// Если список не пуст, очистить список
	void refillCertificates();

public:
	constexpr static unsigned int CertificateEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;

	static inline CertificateStorage* Instance = nullptr;

	CertificateStorage();
	
	// Вызов этого метода подразумевает пересканирование сертификатов, поскольку
	// предполагается, что список сертификатов всегда должен быть актуальным
	Certificate* GetFirstCertificate();

	// Возвращает следующий сертификат из итератора
	// или nullptr, если достигнут конец списка
	Certificate* GetNextCertificate();
	
	~CertificateStorage();
};