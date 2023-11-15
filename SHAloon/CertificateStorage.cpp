#include "pch.h"
#include "CertificateStorage.h"

void CertificateStorage::refillCertificates() {
	for (auto cert : mCertificates) {
		if (cert) delete cert;
	}
	mCertificates.clear();
	hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, certificateEncodingType, 0,
		CERT_SYSTEM_STORE_CURRENT_USER, TEXT("MY"));

	if (!hCertStore) {
		return;
	}

	PCCERT_CONTEXT context = NULL;

	do {
		context = CertEnumCertificatesInStore(hCertStore, context);
		parseCertificateInfo(context);
	} while (context);

	CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG);
	hCertStore = NULL;
}

void CertificateStorage::parseCertificateInfo(PCCERT_CONTEXT context) {
	if (!context) return;

	tstring subjectName, issuerName;

	DWORD len = CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, 0, 0);
	if (!len) return;

	std::vector<TCHAR> buf(len + 1);
	if (CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, &buf[0], len)) {
		subjectName = tstring(buf.begin(), buf.end());
	} else subjectName = TEXT("### error getting subject name ###");

	len = CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, 0, 0);
	if (!len) return;
	buf.clear();
	buf.resize(len + 1);

	if (CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
		issuerName = tstring(buf.begin(), buf.end());
	} else issuerName = TEXT("### error getting issuer name ###");

	auto fileTimeNotAfter = context->pCertInfo->NotAfter;
	SYSTEMTIME st;

	FileTimeToSystemTime(&fileTimeNotAfter, &st);
	
	auto sw = std::setw(2);
	auto sf = std::setfill(TEXT('0'));
	tstringstream ss;
	ss << st.wYear << TEXT("-")
		<< sw << sf << st.wMonth << TEXT("-")
		<< sw << sf << st.wDay;

	tstring notAfter(ss.str());

	auto serialNumber = context->pCertInfo->SerialNumber.pbData;
	auto serialNumberSize = context->pCertInfo->SerialNumber.cbData;

	auto cert = new Certificate();
	cert->SetIssuer(issuerName);
	cert->SetSubject(subjectName);
	cert->SetNotAfter(notAfter);
	cert->SetSerialNumber(serialNumber, serialNumberSize);

	mCertificates.push_back(cert);
}

CertificateStorage::CertificateStorage() {}

Certificate* CertificateStorage::GetFirstCertificate() {
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

CertificateStorage::~CertificateStorage() {
	if (hCertStore) CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG);
	for (auto cert : mCertificates) {
		if (cert) delete cert;
	}
}
