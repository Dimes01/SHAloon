#include "pch.h"
#include "Cryptoprovider.h"

bool Cryptoprovider::getFileData(LPCTSTR szFile, std::vector<BYTE>& bData) {
	namespace fs = std::filesystem;

	tstring logSource = _T("Cryptoprovider::getFileData()");
	tstring fileNameWithQuotes = _T("\"") + tstring(szFile) + _T("\"");

	std::error_code errorCode{};
	fs::path filePath{ szFile };
	auto fileSize = fs::file_size(filePath, errorCode);

	if (errorCode.value() != 0) {
		SetLastError(errorCode.value());
		Logger::WinApiLog(false, logSource, _T("Error getting size of ") + fileNameWithQuotes, LogLevel::LOG_ERROR);
		return false;
	}

	bData.resize(fileSize);

	std::ifstream file(szFile, std::ios::binary);
	if (file.is_open() == false) {
		Logger::Log(false, logSource, _T("Error opening file for reading: ") + fileNameWithQuotes, tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.read(reinterpret_cast<char*>(bData.data()), fileSize);
	file.close();

	Logger::Log(true, logSource, _T("Successfully read data of ") + fileNameWithQuotes, tstring(), LogLevel::LOG_INFO);

	return true;
}

bool Cryptoprovider::saveDataToFile(LPCTSTR szFile, const std::vector<BYTE>& bData) {
	tstring logSource = _T("Cryptoprovider::saveDataToFile()");
	tstring fileNameWithQuotes = _T("\"") + tstring(szFile) + _T("\"");

	std::ofstream file(szFile, std::ios::binary);

	if (file.is_open() == false) {
		Logger::Log(false, logSource, _T("Error opening file for writing ") + fileNameWithQuotes, tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.write(reinterpret_cast<const char*>(bData.data()), bData.size());
	file.close();

	Logger::Log(true, logSource, _T("Successfully written data of ") + fileNameWithQuotes, tstring(), LogLevel::LOG_INFO);

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
}