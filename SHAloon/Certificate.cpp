#include "pch.h"
#include "Certificate.h"

Certificate::Certificate(PCCERT_CONTEXT validPcCertContext) {
	std::vector<TCHAR> buf;

	DWORD len = CertGetNameString(validPcCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, NULL, NULL);
	if (len) {
		buf.resize(len);
		if (CertGetNameString(validPcCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, &buf[0], len)) {
			SetSubject(tstring(buf.begin(), buf.end()));
		}
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("CertificateStorage::ParseCertificateInfo()"),
			               TEXT("Error calling CertGetNameString() 1st time for subject"),
			               errorCode.str(), LogLevel::LOG_WARN);
	}

	len = CertGetNameString(validPcCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, NULL, NULL);
	if (len) {
		buf.clear();
		buf.resize(len);
		if (CertGetNameString(validPcCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
			SetIssuer(tstring(buf.begin(), buf.end()));
		}
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("CertificateStorage::ParseCertificateInfo()"),
			               TEXT("Error calling CertGetNameString() 1st time for issuer"),
			               errorCode.str(), LogLevel::LOG_ERROR);
	}

	auto fileTimeNotAfter = validPcCertContext->pCertInfo->NotAfter;
	SYSTEMTIME st;

	FileTimeToSystemTime(&fileTimeNotAfter, &st);

	auto sw = std::setw(2);
	auto sf = std::setfill(TEXT('0'));
	tstringstream ss;
	ss << st.wYear << TEXT("-")
		<< sw << sf << st.wMonth << TEXT("-")
		<< sw << sf << st.wDay;

	SetNotAfter(ss.str());

	BYTE* pbSerialNumber = validPcCertContext->pCertInfo->SerialNumber.pbData;
	DWORD dwSerialNumberSize = validPcCertContext->pCertInfo->SerialNumber.cbData;

	SetSerialNumber(pbSerialNumber, dwSerialNumberSize);

	SetCertContext(validPcCertContext);
}

void Certificate::SetSubject(const tstring& subject) {
    mSubject = subject;
}

tstring Certificate::GetSubject() {
    return mSubject;
}

void Certificate::SetIssuer(const tstring& issuer) {
    mIssuer = issuer;
}

tstring Certificate::GetIssuer() {
    return mIssuer;
}

void Certificate::SetSerialNumber(const BYTE* serialNumber, const DWORD serialNumberSize) {
    tstringstream ss;

    for (long long i = static_cast<long long>(serialNumberSize) - 1; i >= 0; --i) {
        ss << std::setw(2) << std::setfill(TEXT('0')) << std::hex << (int)(serialNumber[i]);
    }

    mSerialNumberString = ss.str();
}

tstring Certificate::GetSerialNumber() {
    return mSerialNumberString;
}

void Certificate::SetNotAfter(const tstring& notAfter) {
    mNotAfter = notAfter;
}

tstring Certificate::GetNotAfter() {
    return mNotAfter;
}

void Certificate::SetCertContext(PCCERT_CONTEXT certContext) {
    mCertContext = CertDuplicateCertificateContext(certContext);
}

PCCERT_CONTEXT Certificate::GetCertContext() {
    return mCertContext;
}

Certificate::~Certificate() {
    if (mCertContext) CertFreeCertificateContext(mCertContext);
}