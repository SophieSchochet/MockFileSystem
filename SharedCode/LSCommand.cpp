#include "LSCommand.h"
#include <iomanip>

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in) {
	afs_ptr = afs_in;
	aff_ptr = aff_in;
}

int LSCommand::execute(std::string s) {
	set<string> fileNames = afs_ptr->getFileNames();
	if (s == "") {
		int count = 0;
		cout << setw(20);
		for (auto& x : fileNames) {
			cout << x;
			count++;
			if (count % 2 == 0) {
				cout << endl;
			}
		}
		return successful;
	}
	else if (s == "-m") { //Want to display Metadata using dispaly visitor 

	}
	else {
		return commandDoesNotExist;
	}
}

void displayInfo() {
	cout << "ls command outputs the name of all files currently in the system. It is invoked by typing: ls" << endl;
}