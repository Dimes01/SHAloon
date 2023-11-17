#include "pch.h"
#include "Cryptoprovider.h"

bool Cryptoprovider::getFileData(LPCTSTR szFile, std::vector<BYTE>& bData) {
	namespace fs = std::filesystem;

	std::error_code errorCode{};
	fs::path filePath{ szFile };
	auto fileSize = fs::file_size(filePath, errorCode);

	if (errorCode.value() != 0) {
		tstringstream errorCodeStr;
		errorCodeStr << "Error code: 0x" << std::hex << errorCode.value();
		tstring message = TEXT("Error getting size of file \"") + tstring(szFile) + TEXT("\"");
		Logger::Log(false, TEXT("Cryptoprovider::getFileData()"),
			               message, errorCodeStr.str(), LogLevel::LOG_ERROR);
		return false;
	}

	bData.resize(fileSize);

	std::ifstream file(szFile, std::ios::binary);
	if (file.is_open() == false) {
		tstring message = TEXT("Error opening file \"") + tstring(szFile) + TEXT("\" for reading");
		Logger::Log(false, TEXT("Cryptoprovider::getFileData()"),
			               message, TEXT(""), LogLevel::LOG_ERROR);
		return false;
	}

	file.read(reinterpret_cast<char*>(bData.data()), fileSize);
	file.close();

	return true;
}

bool Cryptoprovider::saveDataToFile(LPCTSTR szFile, const std::vector<BYTE>& bData) {
	std::ofstream file(szFile, std::ios::binary);

	if (file.is_open() == false) {
		tstring message = TEXT("Error opening file \"") + tstring(szFile) + TEXT("\" for writing");
		Logger::Log(false, TEXT("Cryptoprovider::saveDataToFile()"),
			message, TEXT(""), LogLevel::LOG_ERROR);
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