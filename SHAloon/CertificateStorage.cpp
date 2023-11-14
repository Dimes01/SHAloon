#include "pch.h"
#include "CertificateStorage.h"

void CertificateStorage::refillCertificates() {
	mCertificates.clear();
	hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, certificateEncodingType, 0,
		CERT_SYSTEM_STORE_CURRENT_USER, _TEXT("MY"));

	if (!hCertStore) {
		return;
	}

	PCCERT_CONTEXT context = NULL;

	while (context = CertEnumCertificatesInStore(hCertStore, context)) {
		parseCertificateInfo(context);
	}

	CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG);
	hCertStore = NULL;
}

void CertificateStorage::parseCertificateInfo(PCCERT_CONTEXT context) {
	std::string subjectName, issuerName;

	DWORD len = CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, 0, 0);
	if (!len) return;

	std::vector<TCHAR> buf(len + 1);
	if (CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, 0, NULL, &buf[0], len)) {
		subjectName = std::string(buf.begin(), buf.end());
	} else subjectName = "### error getting subject name ###";

	len = CertGetNameString(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, 0, 0);
	if (!len) return;
	buf.clear();

	if (CertGetNameStringW(context, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
		issuerName = std::string(buf.begin(), buf.end());
	} else issuerName = "### error getting issuer name ###";

	auto fileTimeNotAfter = context->pCertInfo->NotAfter;
	SYSTEMTIME st;

	FileTimeToSystemTime(&fileTimeNotAfter, &st);
	
	auto sw = std::setw(2);
	auto sf = std::setfill('0');
	std::stringstream ss;
	ss << st.wYear << "-"
		<< sw << sf << st.wMonth << "-"
		<< sw << sf << st.wDay;

	std::string notAfter(ss.str());

	auto serial = context->pCertInfo->SerialNumber.pbData;
	auto size = context->pCertInfo->SerialNumber.cbData;

	char* copy = new char[size + 1];
	strcpy_s(copy, size, reinterpret_cast<char*>(serial));
	copy[size] = '\0';

	std::string serialNumber(copy);
	delete[] copy;

	auto cert = new Certificate();
	cert->SetIssuer(issuerName);
	cert->SetSubject(subjectName);
	cert->SetNotAfter(notAfter);
	cert->SetSerialNumber(serialNumber);

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
}
