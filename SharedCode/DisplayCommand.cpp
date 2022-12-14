#include "../SharedCode/DisplayCommand.h"

using namespace std;


DisplayCommand::DisplayCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
	bdv_ptr = new BasicDisplayVisitor();
}


int DisplayCommand::execute(string s) {
	string fileName = "";
	string extension = "";
	istringstream iss(s);
	iss >> fileName;
	iss >> extension;
	if (extension == "-d") { //Unformatted

		AbstractFile * currentFile = afs_ptr->openFile(fileName);
		if (currentFile == nullptr) {
			return fileNotOpen;
		}
		vector<char> contents = currentFile->read();
		for (char c : contents) {
			cout << c;
		}
		cout << endl;
		afs_ptr->closeFile(currentFile);
		return successful;

	}

	else { //Formatted option
		
		AbstractFile* currentFile = afs_ptr->openFile(s);
		if (currentFile == nullptr) {
			return fileNotOpen;
		}
		currentFile->accept(bdv_ptr);
		cout << endl;
		afs_ptr->closeFile(currentFile);
		return successful;
	}
		return failedCommand;
	
}

void DisplayCommand::displayInfo() {
	cout << "ds <filename> will open a file and display its contents. ds <filename> -d will display unformatted data" << endl;
}