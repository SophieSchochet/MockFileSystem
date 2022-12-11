#include "TouchCommand.h"
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in) {
	afs_ptr = afs_in;
	aff_ptr = aff_in;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <fileName>" << endl;
}

int TouchCommand::execute(string s) {

	AbstractFile* ptr = aff_ptr->createFile(s);
	if (ptr != nullptr) {
		int result = afs_ptr->addFile(s,ptr);
		if (result != successful) {
			delete(ptr);
		} 
		return result;
	}
	else {
		return cannotCreateFile;
	}
}