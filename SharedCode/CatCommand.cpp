#include "CatCommand.h"
#include <sstream>
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}


int CatCommand::execute(std::string s) {
	string filename = "";
	string extension = "";
	istringstream iss(s);
	iss >> filename; 
	iss >> extension;
	AbstractFile* catFile = afs_ptr->openFile(filename);
	if (catFile == nullptr) {
		return fileDoesNotExist;
	}
	bool ifAppend = false;
	if (extension == "-a") {
		ifAppend = true;
	}
	if (ifAppend) {
		vector<char> contents = catFile->read();
		for (char c : contents) {
			cout << c;
		}
		cout << endl; 
	}
	vector<char> cat_user_input;
	string input;
	bool firstIteration = true;
	while (input != ":q" && input != ":wq") {
		//Iterate through string and add each char to tentative changes
		for (char x : input) {
			cat_user_input.push_back(x);
		} 
		//Don't pushback an empty line on the first or last iteration
		getline(cin, input);
		if(!firstIteration && input!= ":q" && input != ":wq") {
			cat_user_input.push_back('\n');
		}
		else {
			firstIteration = false;
		}
	}
	if (input == ":q") {
		cout << "User has quit without saving" << endl;
		afs_ptr->closeFile(catFile);
		return successful;
	}
	else if (input == ":wq") {
		cout << "User has saved and quit." << endl;
		if (ifAppend) {
			int appd_result = catFile->append(cat_user_input);
			afs_ptr->closeFile(catFile);
			return appd_result;
		}
		else {
			int write_result = catFile->write(cat_user_input);
			afs_ptr->closeFile(catFile);
			return write_result;
		}
	}
	else {
		afs_ptr->closeFile(catFile);
		return failedCommand;
	}
}


void CatCommand::displayInfo() {
	cout << "The cat command can be invoked with cat <filename> to write or cat <filename> -a to append." << endl;
	cout << " Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exist without saving." << endl;
}