#include "pch.h"
#include "CertificateStorage.h"

CertificateStorage* CertificateStorage::Instance = nullptr;

void CertificateStorage::refillCertificates() {
	for (auto cert : mCertificates) {
		if (cert) delete cert;
	}

	mCertificates.clear();
	HCERTSTORE hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM, certificateEncodingType, 0,
		CERT_SYSTEM_STORE_CURRENT_USER, TEXT("MY"));

	if (!hCertStore) {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::refillCertificates()"),
						   TEXT("Error opening certificate store"),
						   errorCode.str(), LogLevel::LOG_ERROR);
		return;
	}

	PCCERT_CONTEXT context = NULL;

	do {
		context = CertEnumCertificatesInStore(hCertStore, context);
		parseCertificateInfo(context);
	} while (context);

	if (!CertCloseStore(hCertStore, CERT_CLOSE_STORE_CHECK_FLAG)) {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::refillCertificates()"),
						   TEXT("Error closing certificate store"),
						   errorCode.str(), LogLevel::LOG_ERROR);
	}
}

void CertificateStorage::parseCertificateInfo(PCCERT_CONTEXT context) {
	if (!context) return;

	tstring subjectName, issuerName;

	DWORD len = CertGetNameString(context, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, NULL, NULL);
	if (!len) {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::parseCertificateInfo()"),
						   TEXT("Error with 1st call of CertGetNameString for subject"),
						   errorCode.str(), LogLevel::LOG_ERROR);
		return;
	}

	std::vector<TCHAR> buf(len + 1);
	if (CertGetNameString(context, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, &buf[0], len)) {
		subjectName = tstring(buf.begin(), buf.end());
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::parseCertificateInfo()"),
						   TEXT("Error with 2nd call of CertGetNameString for subject"),
						   errorCode.str(), LogLevel::LOG_ERROR);
		return;
	}

	len = CertGetNameString(context, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, NULL, NULL);
	if (!len) {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::parseCertificateInfo()"),
					       TEXT("Error with 1st call of CertGetNameString for issuer"),
						   errorCode.str(), LogLevel::LOG_ERROR);
		return;
	}
	
	buf.clear();
	buf.resize(len + 1);

	if (CertGetNameString(context, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
		issuerName = tstring(buf.begin(), buf.end());
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::parseCertificateInfo()"),
					       TEXT("Error with 2nd call of CertGetNameString for issuer"),
						   errorCode.str(), LogLevel::LOG_ERROR);
		return;
	}

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

	cert->SetCertContext(CertDuplicateCertificateContext(context));

	mCertificates.push_back(cert);
}

CertificateStorage::CertificateStorage() {}

Certificate* CertificateStorage::GetFirstCertificate() {
	refillCertificates();
	mCertificatesIterator = mCertificates.begin();
	if (mCertificatesIterator == mCertificates.end()) {
		Logger::Log(false, TEXT("Shaloon::CertificateStorage::GetFirstCertificate()"),
						   TEXT("Certificates list is empty"), TEXT(""), LogLevel::LOG_WARN);
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
