#include "CopyCommand.h"
using namespace std;

CopyCommand:: CopyCommand (AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}



int CopyCommand::execute(std::string s) {
	istringstream iss(s);
	string to_copy;
	string new_name;
	if (!((iss >> to_copy) && (iss >> new_name))) {
		cout << "Please enter both the file you wish to copy and the new name you want to use" << endl;
		return failedCommand;
	}
	AbstractFile* file_to_duplicate = afs_ptr->openFile(to_copy);
	if (file_to_duplicate == nullptr) {
		cout << "The file you wish to duplicate was not found" << endl;
		return fileDoesNotExist;
	}
	AbstractFile* new_clone = file_to_duplicate->clone(new_name);
	vector<char> to_write;
	for (char c : file_to_duplicate->read()) {
		to_write.push_back(c);
	}
	if (new_clone->write(to_write) != successful) {
		cout << "Unable to copy contents into a new file" << endl;
		afs_ptr->deleteFile(file_to_duplicate->getName());
		new_clone = nullptr; 
		return failedCommand;
	}
	return successful;
}


void CopyCommand::displayInfo() {
	cout << "The copy command copies a file that exists and adds it to the system with a different name. It is invoked with cp <file_to_copy> <new_name_with_no_extension>" << endl;
}