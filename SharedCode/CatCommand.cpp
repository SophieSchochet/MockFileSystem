#include "CatCommand.h"
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}


int CatCommand::execute(std::string s) {
	AbstractFile* catFile = afs_ptr->openFile(s);
	if (catFile == nullptr) {
		return fileDoesNotExist;
	}
	bool ifAppend = false;
	string extension = s.substr(s.length() - 2);
	if (extension == "-a") {
		s = s.substr(0, s.length() - 3);
		ifAppend = true;
	}
	if (ifAppend) {
		catFile->read();
	}
	vector<char> cat_user_input;
	string input = "";
	while (input != ":q" && input != ":wq") {
		getline(cin, input);
		for (char x : input) {
		cat_user_input.push_back(x);
		}
		cat_user_input.push_back('\n');
	}
	if (input == ":q") {
		cout << "User has quit without saving" << endl;
		return successful;
	}
	else if (input == ":wq") {
		cout << "User has saved and quit." << endl;
		if (ifAppend) {
			return catFile->append(cat_user_input);
		}
		else {
			return catFile->write(cat_user_input);
		}
	}
	else {
		return failedCommand;
	}
}


void CatCommand::displayInfo() {
	cout << "The cat command can be invoked with cat <filename> to write or cat <filename> -a to append." << endl;
	cout << " Enter data you would like to append to the existing file. Enter :wq to save the file and exit, enter :q to exist without saving." << endl;
}