#include "pch.h"
#include "Certificate.h"

Certificate::Certificate(PCCERT_CONTEXT validPcCertContext) {
	mCertContext = CertDuplicateCertificateContext(validPcCertContext);
	setSubject();
	setIssuer();
	setNotAfter();
	setSerialNumber();
}

void Certificate::setSubject() {
	DWORD len = CertGetNameString(mCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, NULL, NULL);
	if (len) {
		std::vector<TCHAR> buf(len);
		if (CertGetNameString(mCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, NULL, NULL, &buf[0], len)) {
			mSubject = buf.data();
		}
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Certificate::setSubject()"),
			TEXT("Error calling CertGetNameString() 1st time for subject"),
			errorCode.str(), LogLevel::LOG_WARN);
	}
}

void Certificate::setIssuer() {
	DWORD len = CertGetNameString(mCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, NULL, NULL);
	if (len) {
		std::vector<TCHAR> buf(len);
		if (CertGetNameString(mCertContext, CERT_NAME_FRIENDLY_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
			mIssuer = buf.data();
		}
	} else {
		tstringstream errorCode;
		errorCode << "WINAPI error code: 0x" << std::hex << GetLastError();
		Logger::Log(false, TEXT("Certificate::setIssuer()"),
			TEXT("Error calling CertGetNameString() 1st time for subject"),
			errorCode.str(), LogLevel::LOG_WARN);
	}
}

void Certificate::setNotAfter() {
	auto fileTimeNotAfter = mCertContext->pCertInfo->NotAfter;
	SYSTEMTIME sysTime;

	FileTimeToSystemTime(&fileTimeNotAfter, &sysTime);

	auto setw = std::setw(2);
	auto setfill = std::setfill(TEXT('0'));
	tstringstream ss;
	ss << sysTime.wYear << TEXT("-")
	   << setw << setfill << sysTime.wMonth << TEXT("-")
	   << setw << setfill << sysTime.wDay;

	mNotAfter = ss.str();
}

void Certificate::setSerialNumber() {
	BYTE* pbSerialNumber = mCertContext->pCertInfo->SerialNumber.pbData;
	DWORD dwSerialNumberSize = mCertContext->pCertInfo->SerialNumber.cbData;
    tstringstream ss;

    for (long long i = static_cast<long long>(dwSerialNumberSize) - 1; i >= 0; --i) {
        ss << std::setw(2) << std::setfill(TEXT('0')) << std::hex << (int)(pbSerialNumber[i]);
    }

    mSerialNumberString = ss.str();
}

tstring Certificate::GetSubject() {
    return mSubject;
}

tstring Certificate::GetIssuer() {
    return mIssuer;
}

tstring Certificate::GetSerialNumber() {
    return mSerialNumberString;
}

tstring Certificate::GetNotAfter() {
    return mNotAfter;
}

PCCERT_CONTEXT Certificate::GetCertContext() {
    return mCertContext;
}

Certificate::~Certificate() {
    if (mCertContext) CertFreeCertificateContext(mCertContext);
}