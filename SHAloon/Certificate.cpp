#include "pch.h"
#include "Certificate.h"

Certificate::Certificate(PCCERT_CONTEXT validPcCertContext) {
	mCertContext = CertDuplicateCertificateContext(validPcCertContext);
	setSubject();
	setIssuer();
	setNotAfter();
	setSerialNumber();

	setNotBefore();
	setSha1Hash();
	setPublicKeyBytes();
	setPublicKeyAlgorithm();
	setSignatureAlgorithm();
	setFullSubject();
	setFullIssuer();
}

void Certificate::FreeCertificateContext() {
	if (mCertContext) {
		CertFreeCertificateContext(mCertContext);
		mCertContext = nullptr;
	}
}

std::basic_string<WCHAR> Certificate::getNameRDNAttrName(const CERT_RDN_ATTR& attr) {
	PCCRYPT_OID_INFO pCOI = CryptFindOIDInfo(CRYPT_OID_INFO_OID_KEY, attr.pszObjId, 0);
	return pCOI->pwszName;
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

void Certificate::setNotBefore() {
	auto fileTimeNotBefore = mCertContext->pCertInfo->NotBefore;
	SYSTEMTIME sysTime;

	FileTimeToSystemTime(&fileTimeNotBefore, &sysTime);

	mNotBefore = std::format(CertificateTimeFormat, sysTime.wYear, sysTime.wMonth, sysTime.wDay);
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
		if (idx < cb - 1) ss << _T(' ');
	}

	mPublicKeyBytes = ss.str();
}

void Certificate::setPublicKeyAlgorithm() {
	auto publicKeyInfo = mCertContext->pCertInfo->SubjectPublicKeyInfo;
	PCCRYPT_OID_INFO pCOI = CryptFindOIDInfo(CRYPT_OID_INFO_OID_KEY, publicKeyInfo.Algorithm.pszObjId, 0);
	if (pCOI && pCOI->pwszName) {
		mPublicKeyAlgorithm = pCOI->pwszName;
	} else {
		mPublicKeyAlgorithm = L"Undefined";
	}
}

void Certificate::setSignatureAlgorithm() {
	auto signatureAlgorithm = mCertContext->pCertInfo->SignatureAlgorithm;
	PCCRYPT_OID_INFO pCOI = CryptFindOIDInfo(CRYPT_OID_INFO_OID_KEY, signatureAlgorithm.pszObjId, 0);
	if (pCOI && pCOI->pwszName) {
		mSignatureAlgorithm = pCOI->pwszName;
	} else {
		mSignatureAlgorithm = L"Undefined";
	}
}

void Certificate::setFullName(const CERT_NAME_BLOB& person, std::basic_string<WCHAR>& name) {
	CRYPT_DATA_BLOB blob;
	ZeroMemory(&blob, sizeof(CRYPT_DATA_BLOB));
	if (!CryptDecodeObjectEx(mCertContext->dwCertEncodingType, X509_NAME, person.pbData, person.cbData,
							 CRYPT_DECODE_ALLOC_FLAG, NULL, &blob.pbData, &blob.cbData)) {
		Logger::WinApiLog(false, _T("Certificate::setFullName()"),
			                     _T("CryptDecodeObjectEx() failed"), LogLevel::LOG_WARN);
		return;
	}
	PCERT_NAME_INFO info = (PCERT_NAME_INFO)(blob.pbData);
	for (long long i = info->cRDN - 1; i >= 0; --i) {
		for (DWORD j = 0; j < info->rgRDN[i].cRDNAttr; ++j) {
			CERT_RDN_ATTR attr = info->rgRDN[i].rgRDNAttr[j];
			auto attrName = getNameRDNAttrName(attr);
			if (j > 0) {
				attrName += std::to_wstring(j);
			}
			DWORD attrSize = CertRDNValueToStrW(attr.dwValueType, &attr.Value, NULL, 0);
			LPWSTR str = new WCHAR[attrSize];
			attrSize = CertRDNValueToStrW(attr.dwValueType, &attr.Value, str, attrSize);
			if (!name.empty()) {
				name += L", ";
			}
			name += attrName + L": " + str;
			delete[] str;
		}
	}
	LocalFree(blob.pbData);
}

void Certificate::setFullSubject() {
	setFullName(mCertContext->pCertInfo->Subject, mFullSubject);
}

void Certificate::setFullIssuer() {
	setFullName(mCertContext->pCertInfo->Issuer, mFullIssuer);
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

tstring Certificate::GetNotBefore() {
	return mNotBefore;
}

tstring Certificate::GetSha1Hash() {
	return mSha1Hash;
}

tstring Certificate::GetPublicKeyBytes() {
	return mPublicKeyBytes;
}

std::basic_string<WCHAR> Certificate::GetPublicKeyAlgorithm() {
	return mPublicKeyAlgorithm;
}

std::basic_string<WCHAR> Certificate::GetSignatureAlgorithm() {
	return mSignatureAlgorithm;
}

std::basic_string<WCHAR> Certificate::GetFullSubject() {
	return mFullSubject;
}

std::basic_string<WCHAR> Certificate::GetFullIssuer() {
	return mFullIssuer;
}

Certificate::~Certificate() {
	FreeCertificateContext();
}