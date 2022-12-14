//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This program defines the CopyCommand class that includes the constructor, the execute command, and the DisplayInfo command
#include "CopyCommand.h"
using namespace std;

//Creates a new CopyCommand object, takes in a pointer to an AbstractFileSyStem
CopyCommand:: CopyCommand (AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}


//The execute function extracts two names from the string parameter, the file to be copied and the new file name
//If the file is successfuly copied, it will return 0 to indicate success. Otherwise, it will return a nonzero value corresponding to the error encountered
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
	afs_ptr->closeFile(file_to_duplicate);
	string copy_name = new_clone->getName();

	//The new copy cannot have the same name
	if (copy_name == to_copy) {
		cout << "Invalid Name" << endl;
		return cannotCreateFile;
	}

	//If the new copy cannot succesfully be added to the file system, the user will be notified and the new copy will be deleted
	if (afs_ptr->addFile(copy_name, new_clone) != successful) {
		cout << "File could not be created" << endl;
		new_clone = nullptr;
		return cannotCreateFile;
	}

	//If we haven't returned an error by this point, it was successful.
	cout << "successfully wrote in cloned file" << endl;
	return successful;
}

//Displays helpful information about the Copy command to the user
void CopyCommand::displayInfo() {
	cout << "The copy command copies a file that exists and adds it to the system with a different name. It is invoked with cp <file_to_copy> <new_name_with_no_extension>" << endl;
}