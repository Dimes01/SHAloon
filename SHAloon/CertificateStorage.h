#pragma once

#include "Certificate.h"
#include "ShaloonUtils.h"


class CertificateStorage {
private:
	const unsigned int certificateEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;

	HCERTSTORE hCertStore = NULL;

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// Пересканирование сертификатов
	// Если список не пуст, очистить список
	void refillCertificates();

	void parseCertificateInfo(PCCERT_CONTEXT context);

public:
	CertificateStorage();
	// Вызов этого метода подразумевает пересканирование сертификатов, поскольку
	// предполагается, что список сертификатов всегда должен быть актуальным
	Certificate* GetFirstCertificate();

	// Возвращает следующий сертификат из итератора
	// или nullptr, если достигнут конец списка
	Certificate* GetNextCertificate();
	~CertificateStorage();
};

