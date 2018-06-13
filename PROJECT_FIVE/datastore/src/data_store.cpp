#include "../includes/data_store.h"

DataStore::DataStore(Crypto *pCrypt) :
		myCrypto(pCrypt) {

}

DataStore::~DataStore(void) {
//	if (this->myCrypto) {
//		delete this->myCrypto;
//		this->myCrypto = 0;
//	}
}

bool DataStore::encrypt(std::string &myString) {
	if (myCrypto) {
		return myCrypto->encrypt(myString);
	} else {
		return false;
	}
}

bool DataStore::decrypt(std::string &myString) {
	if (myCrypto) {
		return myCrypto->decrypt(myString);
	} else {
		return false;
	}
}

