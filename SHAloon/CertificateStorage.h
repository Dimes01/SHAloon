#pragma once
#include <string>
#include <list>
#include <sstream>
#include <wincrypt.h>
#include "Certificate.h"

class CertificateStorage {
private:
	HCERTSTORE hMemoryStore;
	PCCERT_CONTEXT pDesiredCert = NULL;	// ���������� � NULL ��� ������� ��������� � ������� CertFindCertificateInStore

	std::list<Certificate*> mCertificates;
	std::list<Certificate*>::iterator mCertificatesIterator;

	// ���������������� ������������
	// ���� ������ �� ����, �������� ������
	virtual void refillCertificates() = 0;

	void CertFindFirstInMemoryStorage();
	void MakeCertificateInfo(PCERT_INFO pDesiredCertInfo);

public:
	CertificateStorage();
	// ����� ����� ������ ������������� ���������������� ������������, ���������
	// ��������������, ��� ������ ������������ ������ ������ ���� ����������
	Certificate* CertGetFirst();

	// ���������� ��������� ���������� �� ���������
	// ��� nullptr, ���� ��������� ����� ������
	Certificate* GetNextCertificate();
	~CertificateStorage();
};

