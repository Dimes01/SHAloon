#pragma once

#include "Certificate.h"
#include "ShaloonUtils.h"
#include "Logger.h"


class CertificateStorage {
private:
	HCERTSTORE hCertStore = NULL;

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// ���������������� ������������
	// ���� ������ �� ����, �������� ������
	void refillCertificates();

public:
	constexpr static unsigned int CertificateEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;

	static inline CertificateStorage* Instance = nullptr;

	CertificateStorage();
	
	// ����� ����� ������ ������������� ���������������� ������������, ���������
	// ��������������, ��� ������ ������������ ������ ������ ���� ����������
	Certificate* GetFirstCertificate();

	// ���������� ��������� ���������� �� ���������
	// ��� nullptr, ���� ��������� ����� ������
	Certificate* GetNextCertificate();
	
	~CertificateStorage();
};