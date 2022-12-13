#include "CopyCommand.h"
using namespace std;

CopyCommand:: CopyCommand (AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}



int CopyCommand::execute(std::string s) {
	istringstream iss(s);
	string to_copy;
	string new_name;

	//If we can't extract two names, the command is being used incorrectly.
	if (!(iss >> to_copy) || !(iss >> new_name)) {
		cout << "Please enter both the file you wish to copy and the new name you want to use" << endl;
		return failedCommand;
	}
	//If there is a '.' in the new name, it is invalid format
	if (new_name.find(".") < new_name.length()) {
		cout << "Please enter new name without extension." << endl;
		return invalidFileName;
	}
	AbstractFile* file_to_duplicate = afs_ptr->openFile(to_copy);

	//Ensure we could open the file we need to duplicate.
	if (file_to_duplicate == nullptr) {
		cout << "The file you wish to duplicate was not found" << endl;
		return fileDoesNotExist;
	}

	//Make a clone of the file and add it to the system.
	AbstractFile* new_clone = file_to_duplicate->clone(new_name);
	
	if (afs_ptr->addFile(new_clone->getName(), new_clone) != successful) {
		cout << "Invalid name" << endl;
		afs_ptr->deleteFile(new_clone->getName());
		new_clone = nullptr;
		return cannotCreateFile;
	}

	/*//If we can't write the contents of the old file to the new file, command has failed.
	if (afs_ptr->openFile(new_clone->getName())->write(file_to_duplicate->read()) != successful) {
		cout << "Unable to copy contents into a new file" << endl;
		afs_ptr->closeFile(new_clone);
		afs_ptr->deleteFile(new_clone->getName());
		new_clone = nullptr; 
		cout << "failed to write in cloned file" << endl;
		return failedCommand;
	}*/

	//If we haven't returned an error by this point, it was successful.
	cout << "successfully wrote in cloned file" << endl;
	afs_ptr->closeFile(file_to_duplicate);
	afs_ptr->closeFile(new_clone);
	return successful;
}


void CopyCommand::displayInfo() {
	cout << "The copy command copies a file that exists and adds it to the system with a different name. It is invoked with cp <file_to_copy> <new_name_with_no_extension>" << endl;
}