#include "pch.h"
#include "Cryptoprovider.h"

Cryptoprovider::Cryptoprovider() {
	
}

bool Cryptoprovider::IsInitialized() {
	return mInitialized;
}


Cryptoprovider::~Cryptoprovider() {
    //for (auto& certificate : mCertificates) {
    //    if (certificate != nullptr) delete certificate;
    //}
}