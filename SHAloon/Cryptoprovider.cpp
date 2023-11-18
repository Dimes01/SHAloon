#include "pch.h"
#include "Cryptoprovider.h"

bool Cryptoprovider::getFileData(LPCTSTR szFile, std::vector<BYTE>& bData) {
	namespace fs = std::filesystem;

	std::error_code errorCode{};
	fs::path filePath{ szFile };
	auto fileSize = fs::file_size(filePath, errorCode);

	if (errorCode.value() != 0) {
		SetLastError(errorCode.value());
		tstringstream summary;
		summary << _T("Error getting size of file \"") << szFile << _T("\"");
		Logger::WinApiLog(false, _T("Cryptoprovider::getFileData()"),
			                     summary.str(), LogLevel::LOG_ERROR);
		return false;
	}

	bData.resize(fileSize);

	std::ifstream file(szFile, std::ios::binary);
	if (file.is_open() == false) {
		tstringstream message;
		message << _T("Error opening file \"") << szFile << _T("\" for reading");
		Logger::Log(false, _T("Cryptoprovider::getFileData()"),
			               message.str(), tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.read(reinterpret_cast<char*>(bData.data()), fileSize);
	file.close();

	return true;
}

bool Cryptoprovider::saveDataToFile(LPCTSTR szFile, const std::vector<BYTE>& bData) {
	std::ofstream file(szFile, std::ios::binary);

	if (file.is_open() == false) {
		tstringstream message;
		message << _T("Error opening file \"") << szFile << _T("\" for writing");
		Logger::Log(false, _T("Cryptoprovider::saveDataToFile()"),
			               message.str(), tstring(), LogLevel::LOG_ERROR);
		return false;
	}

	file.write(reinterpret_cast<const char*>(bData.data()), bData.size());
	file.close();

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