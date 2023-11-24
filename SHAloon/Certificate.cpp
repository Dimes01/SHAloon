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
	DWORD len = CertGetNameString(mCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, NULL, NULL, NULL, NULL);
	if (len) {
		std::vector<TCHAR> buf(len);
		if (CertGetNameString(mCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, NULL, NULL, &buf[0], len)) {
			mSubject = buf.data();
		}
	} else {
		Logger::WinApiLog(false, _T("Certificate::setSubject()"),
			                     _T("Error calling CertGetNameString() 1st time for subject"),
			                     LogLevel::LOG_WARN);
	}
}

void Certificate::setIssuer() {
	DWORD len = CertGetNameString(mCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, NULL, NULL);
	if (len) {
		std::vector<TCHAR> buf(len);
		if (CertGetNameString(mCertContext, CERT_NAME_SIMPLE_DISPLAY_TYPE, CERT_NAME_ISSUER_FLAG, NULL, &buf[0], len)) {
			mIssuer = buf.data();
		}
	} else {
		Logger::WinApiLog(false, _T("Certificate::setIssuer()"),
			                     _T("Error calling CertGetNameString() 1st time for issuer"),
			                     LogLevel::LOG_WARN);
	}
}

void Certificate::setNotAfter() {
	auto fileTimeNotAfter = mCertContext->pCertInfo->NotAfter;
	SYSTEMTIME sysTime;

	FileTimeToSystemTime(&fileTimeNotAfter, &sysTime);

	mNotAfter = std::format(CertificateTimeFormat, sysTime.wYear, sysTime.wMonth, sysTime.wDay);
}

void Certificate::setSerialNumber() {
	BYTE* pbSerialNumber = mCertContext->pCertInfo->SerialNumber.pbData;
	long long serialNumberSize = static_cast<long long>(mCertContext->pCertInfo->SerialNumber.cbData);
    tstringstream ss;

    for (long long i = serialNumberSize - 1; i >= 0; --i) {
		ss << std::format(CertificateDataByteFormat, (int)(pbSerialNumber[i]));
    }

    mSerialNumberString = ss.str();
}

void Certificate::setSha1Hash() {
	DWORD size{};
	CertGetCertificateContextProperty(mCertContext, CERT_SHA1_HASH_PROP_ID, NULL, &size);
	if (size) {
		std::vector<BYTE> data(size);
		tstringstream ss;
		CertGetCertificateContextProperty(mCertContext, CERT_SHA1_HASH_PROP_ID, data.data(), &size);

		for (DWORD idx = 0; idx < size; ++idx) {
			ss << std::format(CertificateDataByteFormat, (int)(data[idx]));
		}

		mSha1Hash = ss.str();
	} else {
		Logger::WinApiLog(false, _T("Certificate::setSha1Hash()"),
								 _T("Error calling CertGetCertificateContextProperty() 1st time"),
							     LogLevel::LOG_WARN);
	}
}

void Certificate::setPublicKeyBytes() {
	auto pb = mCertContext->pCertInfo->SubjectPublicKeyInfo.PublicKey.pbData;
	auto cb = mCertContext->pCertInfo->SubjectPublicKeyInfo.PublicKey.cbData;
	tstringstream ss;

	for (DWORD idx = 0; idx < cb; ++idx) {
		ss << std::format(CertificateDataByteFormat, (int)(pb[idx]));
	}

	mPublicKeyBytes = ss.str();
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

tstring Certificate::GetSha1Hash() {
	return mSha1Hash;
}

tstring Certificate::GetPublicKeyBytes() {
	return mPublicKeyBytes;
}

Certificate::~Certificate() {
    if (mCertContext) CertFreeCertificateContext(mCertContext);
}