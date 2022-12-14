//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This porgram defines the DisplayCommand class that contains a constructor, the execute function, and a function to display information about the command
#include "../SharedCode/DisplayCommand.h"

using namespace std;

//Constructor to create a DisplayCommand, takes in a pointer to the abstract fle system
DisplayCommand::DisplayCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
	bdv_ptr = new BasicDisplayVisitor();
}

//The execute function separates the string parameter into the fileName and extension and displays the file contents wither formatted or unformatted based on the extension provided
//Execute returns either 0 to indicate success or a nonzero value corresponding to the error encountered
int DisplayCommand::execute(string s) {
	string fileName = "";
	string extension = "";
	istringstream iss(s);
	iss >> fileName;
	iss >> extension;
	if (extension == "-d") { //Unformatted

		AbstractFile * currentFile = afs_ptr->openFile(fileName);

		//If opening the file returned a nullPtr, the file could not be opened and execute can stop
		if (currentFile == nullptr) {
			return fileNotOpen;
		}

		//if the user wants the contents unformatted we can simply cout the contents
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
		//If openFile returned a nullptr, the file could not be opened and execute can stop
		if (currentFile == nullptr) {
			return fileNotOpen;
		}
		//Since the user has opted for formatted, we call accept and pass in the display visitor as the parameter
		currentFile->accept(bdv_ptr);
		cout << endl;
		afs_ptr->closeFile(currentFile);
		return successful;
	}
	//If the program has executed to this point, the command has failed
		return failedCommand;
	
}

//Displays helpful information about the display command to the user
void DisplayCommand::displayInfo() {
	cout << "ds <filename> will open a file and display its contents. ds <filename> -d will display unformatted data" << endl;
}