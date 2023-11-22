#include "pch.h"
#include "CertificateStorage.h"

void CertificateStorage::refillCertificates() {
	tstring logSource = _T("CertificateStorage::refillCertificates()");

	for (auto cert : mCertificates) {
		if (cert) delete cert;
	}

	mCertificates.clear();
	HCERTSTORE hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, CertificateEncodingType, 0,
		CERT_SYSTEM_STORE_CURRENT_USER, TEXT("MY"));

	if (!hCertStore) {
		Logger::WinApiLog(false, logSource, _T("Error opening certificate store"), LogLevel::LOG_ERROR);
		return;
	}

	PCCERT_CONTEXT context = CertEnumCertificatesInStore(hCertStore, NULL);

	while (context) {
		Certificate* cert = new Certificate(context);
		mCertificates.push_back(cert);
		context = CertEnumCertificatesInStore(hCertStore, context);
	}

	if (!CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG)) {
		Logger::WinApiLog(false, logSource, _T("Error closing certificate store"), LogLevel::LOG_ERROR);
	}

	Logger::Log(true, logSource, _T("Successfully refilled certificates"), _T(""), LogLevel::LOG_INFO);
}

CertificateStorage::CertificateStorage() {}

Certificate* CertificateStorage::GetFirstCertificate() {
	refillCertificates();
	mCertificatesIterator = mCertificates.begin();
	if (mCertificatesIterator == mCertificates.end()) {
		Logger::Log(false, _T("CertificateStorage::GetFirstCertificate()"), _T("Certificates list is empty"), tstring(), LogLevel::LOG_WARN);
		return nullptr;
	}
	return *mCertificatesIterator;
}

Certificate* CertificateStorage::GetNextCertificate() {
	++mCertificatesIterator;
	if (mCertificatesIterator == mCertificates.end()) return nullptr;
	return *mCertificatesIterator;
}

CertificateStorage::~CertificateStorage() {
	for (auto cert : mCertificates) {
		if (cert) delete cert;
	}
}
