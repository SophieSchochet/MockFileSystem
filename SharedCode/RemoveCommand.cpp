//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the functions of the RemoveCommand class

#include "RemoveCommand.h"

using namespace std;

//Constructs a RemoveCommand given a pointer to an AbstractFileSystem
RemoveCommand::RemoveCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;

}

//Displays helpful information about the RemoveCommand to the user
void RemoveCommand::displayInfo() {
	cout << "Remove command removes a given file from the file system. It is invoked with: rm <filename>" << endl;
}

//Takes in the file name as a parameter and returns the result of calling delete on the file
int RemoveCommand::execute(std::string s) {
	int result = afs_ptr->deleteFile(s);
	return result; 
}