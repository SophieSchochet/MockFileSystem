#include "RemoveCommand.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in) {
	afs_ptr = afs_in;
	aff_ptr = aff_in;
}

void RemoveCommand::displayInfo() {
	cout << "Remove command removes a given file from the file system. It is invoked with: rm <filename>" << endl;
}

int RemoveCommand::execute(std::string s) {
	int result = afs_ptr->deleteFile(s);
	return result; 
}