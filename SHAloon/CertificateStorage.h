#pragma once

#include "Certificate.h"
#include "ShaloonUtils.h"
#include "Logger.h"


class CertificateStorage {
private:
	const unsigned int certificateEncodingType = PKCS_7_ASN_ENCODING | X509_ASN_ENCODING;

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// ���������������� ������������
	// ���� ������ �� ����, �������� ������
	void refillCertificates();

	void parseCertificateInfo(PCCERT_CONTEXT context);

public:
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