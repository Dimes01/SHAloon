#include "pch.h"
#include "CertificateStorage.h"
#include "ShaloonUtils.h"

void CertificateStorage::CertFindFirstInMemoryStorage()
{
	pDesiredCert = CertFindCertificateInStore(hMemoryStore, X509_ASN_ENCODING, 0, CERT_FIND_ANY, NULL, NULL);
	MakeCertificateInfo(pDesiredCert->pCertInfo);
}

void CertificateStorage::MakeCertificateInfo(PCERT_INFO pDesiredCertInfo)
{
	std::stringstream ss(pDesiredCertInfo->Subject.cbData);
	std::string subject(ss.str());
	ss.clear();
	ss << pDesiredCertInfo->SubjectPublicKeyInfo.PublicKey.cbData;
	std::string public_key(ss.str());
	ss.clear();
	Certificate cert(subject, public_key);
	mCertificates.push_back(&cert);
}

CertificateStorage::CertificateStorage()
{
	hMemoryStore = CertOpenStore(CERT_STORE_PROV_MEMORY, 0, NULL, 0, NULL);
}

Certificate* CertificateStorage::CertGetFirst() {
	refillCertificates();
	mCertificatesIterator = mCertificates.begin();
	if (mCertificatesIterator == mCertificates.end()) return nullptr;
	return *mCertificatesIterator;
}

Certificate* CertificateStorage::GetNextCertificate() {
	++mCertificatesIterator;
	if (mCertificatesIterator == mCertificates.end()) return nullptr;
	return *mCertificatesIterator;
}

CertificateStorage::~CertificateStorage()
{
	if (hMemoryStore) CertCloseStore(hMemoryStore, CERT_CLOSE_STORE_CHECK_FLAG);
}
