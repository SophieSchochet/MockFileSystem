//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the LSCommand class that includes a constructor, the execute function, and a DisplayInfo method
#include "LSCommand.h"
#include <iomanip>

using namespace std;

//Constructor to create an LSCommand, takes in a pointer to an AbstractFileSystem and creates a pointer to a new MetadataDisplayVisitor
LSCommand::LSCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
	mdv_ptr = new MetadataDisplayVisitor();
}

//execute displays filen names or file names and their metadata depending on user input
//execute returns 0 to indicate success or a nonzero value to indicate the error incountered
int LSCommand::execute(std::string s) {
	set<string> fileNames = afs_ptr->getFileNames();
	//If there was no extension given by the user, we can print the file names
	if (s == "") {
		int count = 0;
		for (auto& fileName : fileNames) {
			cout << setw(20) << fileName;
			count++;
			if (count % 2 == 0) {
				cout << endl;
			}
		}
		cout << endl; //this is to put the  prompt on the next line
		return successful;
	}
	else if (s == "-m") { //Want to display Metadata using the metadata visitor 
		for (auto& fileName : fileNames) {
			AbstractFile* currentFile = afs_ptr->openFile(fileName);
			currentFile->accept(mdv_ptr);
			afs_ptr->closeFile(currentFile);
		}
		return successful;
	}
	//if the program has executed to this point, the command has failed
	else {
		return commandDoesNotExist;
	}
}

//Displays helpful information about the LS command to the user
void LSCommand::displayInfo() {
	cout << "ls command outputs the name of all files currently in the system. It is invoked by typing: ls" << endl;
}