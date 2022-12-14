//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the methods implemented by the TouchCommand class

#include "..\SharedCode\TouchCommand.h"
#include "..\SharedCode\PasswordProxy.h"
using namespace std;

//Constrcts a TouchCommand given a pointer to an AbstractFileSystem and an AbstractFileFactory
TouchCommand::TouchCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in) {
	afs_ptr = afs_in;
	aff_ptr = aff_in;
}

//Dislays helpful information about the Touch command to the user
void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <fileName>" << endl;
}

//Execute separates the string parameter into the filename and extension (if aplicable),creates a new file, and password protects the file if the user has used the -p extension
//Execute returns 0 to indicate success or a nonzero return value corresponding to the error encountered
int TouchCommand::execute(string s) {
	AbstractFile* ptr;
	string fileName = "";
	string extension = "";
	istringstream iss(s);
	iss >> fileName;
	ptr = aff_ptr->createFile(fileName);
	//Checks to see if file could be created
	if (ptr != nullptr) {
		if (iss >> extension) {
			//If the user inputs -p after the file name, the new file will need to be password protected
			if (extension == "-p") {
				string in_pswd;
				//prompts the user for a password
				cout << "What is the password you want to create?" << endl;
				getline(cin, in_pswd);
				//creates a password proxy using the new file and the user's inputted password and adds the proxy to the file system
				PasswordProxy* pswd = new PasswordProxy(ptr, in_pswd);
				int result = afs_ptr->addFile(fileName, pswd);
				//notifies user if the file cannot be added to the system
				if (result != successful) {
					cout << "Unable to add file to system." << endl;
					delete(ptr);
				}
				return result;
			}
		}
		//if the user does not input the extension -p, a normal file can be created and inserted into the fiile system
		else {
			cout << "creating new file" << endl;
			int result = afs_ptr->addFile(fileName, ptr);
			if (result != successful) {
				delete(ptr);
			}
			return result;
		}
	}
	//if the call to createFile returns a nullptr then the file could not be created
	else {
		return cannotCreateFile;
	}
	//if the program has executed to here the command has failed
	return failedCommand;
}