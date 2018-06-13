#include "../includes/data_store_file.h"
#include "../includes/string_data.h"
#include <fstream>

DataStore_File::DataStore_File(std::string fileName, Crypto *crypto) :
		DataStore(crypto), myFileName(fileName) {

}

DataStore_File::~DataStore_File(void) {

}

bool DataStore_File::load(std::vector<String_Data> &myVector) {
	std::fstream open_stream;
	if (openFile(open_stream, myFileName, std::ios_base::in)) {
		std::string line_im_on;
		std::string empty_string;
		int empty;
		while (!open_stream.eof() && getline(open_stream, line_im_on)) {
			if (decrypt(line_im_on)) {
				std::cout << "CAN DECRYPT, ";
				String_Data dummy("", 0);
				dummy.parseData(line_im_on, empty_string, empty);
				String_Data s = String_Data(empty_string, empty);
				myVector.push_back(s);
			} else {
				std::cout << "CANNOT DECRYPT, ";
				String_Data dummy("", 0);
				dummy.parseData(line_im_on, empty_string, empty);
				String_Data s = String_Data(empty_string, empty);
				myVector.push_back(s);
			}
		}
//		std::cout << myVector.size() << std::endl;
		closeFile(open_stream);
		return true;
	} else {
		return false;
	}
}

bool DataStore_File::save(std::vector<String_Data> &myVector) {
	std::fstream open_stream;
	if (openFile(open_stream, myFileName, std::ios_base::out)) {
		for (unsigned int i = 0; i < myVector.size(); i++) {
			String_Data a_string = myVector[i];
			std::string output_string_to_file = a_string.serialize();
			if (encrypt(output_string_to_file)) {
				std::cout << "CAN ENCRYPT, ";
				open_stream << output_string_to_file;
				open_stream << std::endl;
			} else {
				std::cout << "CANNOT ENCRYPT,";
				open_stream << output_string_to_file;
				open_stream << std::endl;
			}
		}
		closeFile(open_stream);
		return true;
	}
	return false;
}

bool DataStore_File::openFile(std::fstream& myfile,
		const std::string& myFileName, std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str(), mode);
	return myfile.is_open();
}

void DataStore_File::closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}
