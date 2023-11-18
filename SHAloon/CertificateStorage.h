#pragma once

#include "Certificate.h"
#include "ShaloonUtils.h"
#include "Logger.h"


class CertificateStorage {
private:
	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// ���������������� ������������
	// ���� ������ �� ����, �������� ������
	void refillCertificates();

public:
	const static unsigned int CertificateEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;

	static CertificateStorage* Instance;

	CertificateStorage();
	
	// ����� ����� ������ ������������� ���������������� ������������, ���������
	// ��������������, ��� ������ ������������ ������ ������ ���� ����������
	Certificate* GetFirstCertificate();

	// ���������� ��������� ���������� �� ���������
	// ��� nullptr, ���� ��������� ����� ������
	Certificate* GetNextCertificate();
	
	~CertificateStorage();
};