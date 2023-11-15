#include "pch.h"
#include "Cryptoprovider.h"

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