#include "pch.h"
#include "Cryptoprovider.h"

std::vector<tstring> Cryptoprovider::getAllCSPNames() {
	DWORD  cbName{};
	DWORD  dwType{};
	DWORD dwIndex{};
	std::vector<tstring> cspNames;

	while (CryptEnumProviders(dwIndex, NULL, 0, &dwType, NULL, &cbName)) {
		tstring name(cbName / sizeof(TCHAR) - 1, TCHAR{});
		if (CryptEnumProviders(dwIndex++, NULL, 0, &dwType, name.data(), &cbName)) {
			cspNames.push_back(name);
		}
	}

	return cspNames;
}

bool Cryptoprovider::getFileData(LPCTSTR szFile, std::vector<BYTE>& bData) {
	namespace fs = std::filesystem;

	tstring logSource = _T("Cryptoprovider::getFileData()");
	tstring fileName(szFile);
	
	std::error_code errorCode{};
	fs::path filePath{ szFile };
	auto fileSize = fs::file_size(filePath, errorCode);

	if (errorCode.value() != 0) {
		SetLastError(errorCode.value());
		Logger::WinApiLog(false, logSource, _T("Error getting size of ") + fileName, LogLevel::LOG_ERROR);
		return false;
	}

	bData.resize(fileSize);

	std::ifstream file(szFile, std::ios::binary);
	if (file.is_open() == false) {
		Logger::Log(false, logSource, _T("Error opening file for reading: ") + fileName, tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.read(reinterpret_cast<char*>(bData.data()), fileSize);
	file.close();

	Logger::Log(true, logSource, _T("Successfully read data of ") + fileName, tstring(), LogLevel::LOG_INFO);

	return true;
}

bool Cryptoprovider::saveDataToFile(LPCTSTR szFile, const std::vector<BYTE>& bData) {
	tstring logSource = _T("Cryptoprovider::saveDataToFile()");
	tstring fileName(szFile);

	std::ofstream file(szFile, std::ios::binary);

	if (file.is_open() == false) {
		Logger::Log(false, logSource, _T("Error opening file for writing ") + fileName, tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.write(reinterpret_cast<const char*>(bData.data()), bData.size());
	file.close();

	Logger::Log(true, logSource, _T("Successfully written data of ") + fileName, tstring(), LogLevel::LOG_INFO);

	return true;
}

Cryptoprovider::Cryptoprovider() {
	
}

bool Cryptoprovider::IsInitialized() {
	return mInitialized;
}


Cryptoprovider::~Cryptoprovider() {
    if (hCryptProv) {
        CryptReleaseContext(hCryptProv, 0);
    }
	if (verificationCertificate) {
		delete verificationCertificate;
	}
	if (decryptionCertificate) {
		delete decryptionCertificate;
	}
}