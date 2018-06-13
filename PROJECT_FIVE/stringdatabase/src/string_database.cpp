#include "../includes/string_database.h"
#include <mutex>
String_Database::String_Database(void) {

}

String_Database::~String_Database(void) {

}

//if not seen yet then add myString to myStrings
//otherwise increment the count for myString
void String_Database::add(std::string &myString) {
	//String_Data temp;
	//std::lock_guard<std::mutex> m(mutex);

	if (myStrings.size() == 0) {
		mutex.lock();
		String_Data temp(myString, 1);
		myStrings.push_back(temp);
		mutex.unlock();

	} else {
		int count = 1;
		mutex.lock();
		int last_index = myStrings.size() - 1;
		mutex.unlock();
		std::string empty_string;

		for (int i = 0; i < myStrings.size(); i++) {
			mutex.lock();
			std::string vect_string = myStrings[i].serialize();
			myStrings[i].parseData(vect_string, empty_string, count);
			if (myString == empty_string) {
				myStrings[i].increment();
			} else if (i == last_index && count == 1) {
				String_Data new_data(myString, count);
				myStrings.push_back(new_data);
				break;

			}
			mutex.unlock();

		}
	}
}

//get number of times myString has been seen (or added with add)
int String_Database::getCount(std::string &myString) {
	for (unsigned int i = 0; i < myStrings.size(); i++) {
		mutex.lock();
		int empty_int;
		std::string empty_string;
		String_Data temp = myStrings[i];
		std::string my_string = temp.serialize();
		temp.parseData(my_string, empty_string, empty_int);
		if (myString == empty_string) {
			return empty_int;
		}
		mutex.unlock();
	}
	return 0;
}

//clear the myStrings vector
void String_Database::clear() {
	myStrings.clear();
}

//load from datastore, returns
//false if myDataStore = 0
//otherwise returns myDataStore->load results
bool String_Database::load(DataStore *myDataStore) {
	if (myDataStore == 0) {
		return false;
	}
	return myDataStore->load(myStrings);
}

//save to datastore,returns
//false if myDataStore = 0
//otherwise returns myDataStore->save results
bool String_Database::save(DataStore *myDataStore) {
	if (myDataStore == 0) {
		return false;
	}
	return myDataStore->save(myStrings);
}
