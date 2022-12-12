#include "LSCommand.h"
#include <iomanip>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
	mdv_ptr = new MetadataDisplayVisitor();
}

int LSCommand::execute(std::string s) {
	set<string> fileNames = afs_ptr->getFileNames();
	if (s == "") {
		int count = 0;
		for (auto& fileName : fileNames) {
			cout << setw(20) << fileName;
			count++;
			if (count % 2 == 0) {
				cout << endl;
			}
		}
		return successful;
	}
	else if (s == "-m") { //Want to display Metadata using dispaly visitor 
		//cout << setw(20);
		for (auto& fileName : fileNames) {
			AbstractFile* currentFile = afs_ptr->openFile(fileName);
			currentFile->accept(mdv_ptr);
		}
		return successful;
	}
	else {
		return commandDoesNotExist;
	}
}

void LSCommand::displayInfo() {
	cout << "ls command outputs the name of all files currently in the system. It is invoked by typing: ls" << endl;
}