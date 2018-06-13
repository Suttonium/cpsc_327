#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <sstream>
#include "../stringdatabase/includes/string_database.h"
#include <vector>
#include "../datastore/includes/data_store_file.h"
#include <fstream>
#include "../crypto/includes/crypto_AES.h"
#include <thread>

//I've provided some hints in the form of comments and commented out code
//use them if you wish

////global database object
String_Database myGlobalCache;

bool testSerialization(const std::string &MYFILE1, const std::string &MYFILE2,
		Crypto *pCrypto) {
	DataStore_File myDataStore_File1(MYFILE1, pCrypto);
	myGlobalCache.save(&myDataStore_File1);

	//clear cache
	myGlobalCache.clear();
	std::cout << "Clearing Cache\n";

	//load it
	myGlobalCache.load(&myDataStore_File1);
	std::cout << "Loading from file " + MYFILE1 + " \n";

	//save to a different file
	DataStore_File myDataStore_File2(MYFILE2, pCrypto);
	myGlobalCache.save(&myDataStore_File2);
	std::cout << "Saving to file " + MYFILE2 + " \n";

	//I use my own objects here to compare the files
	return true;
}

void test_encrypt_and_decrypt_with_a_nonnull_crypto() {
	std::cout << "                ########## TEST ONE ##########" << std::endl;
	std::cout
			<< "TEST CASE:                  TESTING WITH A NONNULL CRYPTO OBJECT"
			<< std::endl;
	char* crypt_string = "I Like Rollos...";
	Crypto_AES *pcrypto_thing = new Crypto_AES(crypt_string);
	std::string string_one = "HOPEFULLY THIS WORKS CORRECTLY";
	std::string fileName = "test_file.txt";
	DataStore_File temp(fileName, pcrypto_thing);
	std::vector<String_Data> myVector;
	String_Data s(string_one, 1);

	//add string_data to vector
	myVector.push_back(s);

	std::string test_string_for_later = s.serialize();

	std::cout << "ORIGINAL SERIALIZED STRING: " << test_string_for_later
			<< std::endl;

	std::cout << "SAVE STATE:                 ";
	if (temp.save(myVector)) {
		std::cout << "SAVED" << std::endl;
	} else {
		std::cout << "DID NOT SAVE" << std::endl;

	}

	std::fstream open_stream;
	open_stream.open(fileName.c_str());
	std::cout << "OPEN STATE:                 ";
	if (open_stream.is_open()) {
		std::cout << "OPEN" << std::endl;
		std::string temps;
		while (!open_stream.eof() && getline(open_stream, temps)) {
			std::cout << "STRING READ FROM FILE:      " << temps << std::endl;
		}
	} else {
		std::cout << "DID NOT OPEN" << std::endl;
	}

	myVector.clear();

	std::cout << "CLEARING VECTOR" << std::endl;
	std::cout << "LOADING DATA BACK FROM FILE" << std::endl;
	std::cout << "LOAD STATE:                 ";
	if (temp.load(myVector)) {
		std::cout << "LOADED UP" << std::endl;
	} else {
		std::cout << "DID NOT LOAD" << std::endl;
	}

	std::string temp_line;
	for (unsigned int i = 0; i < myVector.size(); i++) {
		temp_line = myVector[i].serialize();
		std::cout << "ORIGINAL SERIALIZED STRING: " << temp_line << std::endl;
	}
}

void test_encrypt_and_decrypt_with_a_null_crypto() {
	std::cout << "                ########## TEST TWO ##########" << std::endl;
	std::cout << "TEST CASE:                  TESTING WITH A NULL CRYPTO OBJECT"
			<< std::endl;
	std::string string_one = "HOPEFULLY THIS WORKS CORRECTLY";
	std::string fileName = "test_file.txt";
	DataStore_File temp(fileName, 0);
	std::vector<String_Data> myVector;
	String_Data s(string_one, 1);

	//add string_data to vector
	myVector.push_back(s);

	std::string test_string_for_later = s.serialize();

	std::cout << "ORIGINAL SERIALIZED STRING: " << test_string_for_later
			<< std::endl;

	std::cout << "SAVE STATE:                 ";
	if (temp.save(myVector)) {
		std::cout << "SAVED" << std::endl;
	} else {
		std::cout << "DID NOT SAVE" << std::endl;

	}

	std::fstream open_stream;
	open_stream.open(fileName.c_str());
	std::cout << "OPEN STATE:                 ";
	if (open_stream.is_open()) {
		std::cout << "OPEN" << std::endl;
		std::string temps;
		while (!open_stream.eof() && getline(open_stream, temps)) {
			std::cout << "STRING READ FROM FILE:      " << temps << std::endl;
		}
	} else {
		std::cout << "DID NOT OPEN" << std::endl;
	}

	myVector.clear();

	std::cout << "CLEARING VECTOR" << std::endl;
	std::cout << "LOADING DATA BACK FROM FILE" << std::endl;
	std::cout << "LOAD STATE:                 ";
	if (temp.load(myVector)) {
		std::cout << "LOADED UP" << std::endl;
	} else {
		std::cout << "DID NOT LOAD" << std::endl;
	}

	std::string temp_line;
	for (unsigned int i = 0; i < myVector.size(); i++) {
		temp_line = myVector[i].serialize();
		std::cout << "ORIGINAL SERIALIZED STRING: " << temp_line << std::endl;
	}
}

void add_strings_to_database(std::string string_x) {
	for (unsigned int i = 0; i < 20; i++) {
		myGlobalCache.add(string_x);
	}
}

void multi_thread_test() {
	std::string string_1 = "STRING ONE";
	std::string string_2 = "STRING TWO";
	std::string string_3 = "STRING THREE";
	std::string string_4 = "STRING FOUR";
	std::string string_5 = "STRING FIVE";
	std::string string_6 = "STRING SIX";
	std::string string_7 = "STRING SEVEN";
	std::string string_8 = "STRING EIGHT";
	std::string string_9 = "STRING NINE";
	std::string string_10 = "STRING TEN";
	std::string string_11 = "STRING ELEVEN";
	std::string string_12 = "STRING TWELVE";
	std::string string_13 = "STRING THIRTEEN";
	std::string string_14 = "STRING FOURTEEN";
	std::string string_15 = "STRING FIFTEEN";
	std::string string_16 = "STRING SIXTEEN";
	std::string string_17 = "STRING SEVENTEEN";
	std::string string_18 = "STRING EIGHTEEN";
	std::string string_19 = "STRING NINTEEN";
	std::string string_20 = "STRING TWENTY";

	std::thread thread_one(add_strings_to_database, string_1);
	std::thread thread_two(add_strings_to_database, string_2);
	std::thread thread_three(add_strings_to_database, string_3);
	std::thread thread_four(add_strings_to_database, string_4);
	std::thread thread_five(add_strings_to_database, string_5);
	std::thread thread_six(add_strings_to_database, string_6);
	std::thread thread_seven(add_strings_to_database, string_7);
	std::thread thread_eight(add_strings_to_database, string_8);
	std::thread thread_nine(add_strings_to_database, string_9);
	std::thread thread_ten(add_strings_to_database, string_10);
	std::thread thread_eleven(add_strings_to_database, string_11);
	std::thread thread_twelve(add_strings_to_database, string_12);
	std::thread thread_thirteen(add_strings_to_database, string_13);
	std::thread thread_fourteen(add_strings_to_database, string_14);
	std::thread thread_fifteen(add_strings_to_database, string_15);
	std::thread thread_sixteen(add_strings_to_database, string_16);
	std::thread thread_seventeen(add_strings_to_database, string_17);
	std::thread thread_eighteen(add_strings_to_database, string_18);
	std::thread thread_nineteen(add_strings_to_database, string_19);
	std::thread thread_twenty(add_strings_to_database, string_20);

	thread_one.join();
	thread_two.join();
	thread_three.join();
	thread_four.join();
	thread_five.join();
	thread_six.join();
	thread_seven.join();
	thread_eight.join();
	thread_nine.join();
	thread_ten.join();
	thread_eleven.join();
	thread_twelve.join();
	thread_thirteen.join();
	thread_fourteen.join();
	thread_fifteen.join();
	thread_sixteen.join();
	thread_seventeen.join();
	thread_eighteen.join();
	thread_nineteen.join();
	thread_twenty.join();

//	for (auto& th : threads) {
//		th.join();
//	}

	testSerialization("file_one.txt", "file_two.txt", 0);
	Crypto_AES *myCrypto = new Crypto_AES("I Like Rollos   ");
	testSerialization("file_one.txt", "file_two.txt", myCrypto);

}

void test_string_tracking_through_database() {
	std::cout << "TESTING TRACKING MULTIPLE COPIES OF ONE STRING IN DATABASE"
			<< std::endl;
	String_Database database;
	std::string the_string = "the";
	for (unsigned int i = 0; i < 10; i++) {
		database.add(the_string);
	}

	std::string string_to_look_for = "the";

	int the_occurences = database.getCount(string_to_look_for);
	std::cout << "RESULT SHOULD BE 10: " << the_occurences << std::endl;
}

int main() {
	test_encrypt_and_decrypt_with_a_nonnull_crypto();
	std::cout << std::endl;
	test_encrypt_and_decrypt_with_a_null_crypto();
	std::cout << std::endl;
	test_string_tracking_through_database();
	multi_thread_test();
	std::cout << std::endl;

	//I created and ran a bunch(20) of threads that added different strings to a string_database instance

	//Then I waited for all of them to finish so my program did not crash

	//Then I went through my string_database instance and made sure that it held the correct data

	//then I tested  serialization
	//first without encryption,
	//testSerialization(NO_ENCRYPT_FILE1, NO_ENCRYPT_FILE2, 0);

	//then with
	//Crypto_AES myCrypto("I Like Rollos   ");
	//testSerialization(ENCRYPT_FILE1, ENCRYPT_FILE2, &myCrypto);
}
