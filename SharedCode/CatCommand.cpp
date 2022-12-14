//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the various functions within the CatCommand class as well as a CatCommand constructor

#include "CatCommand.h"
#include <sstream>
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}

//Execute separates the string parameter into its name and extension, opens the file if possible, then stores a vector of user input.
//If the user saves and quits, the file is either written to or appended based on the extension, but if they simply quit the file is not changed.
//Execute returns either 0 to indicate success or a nonzero return value to correspond to an error
int CatCommand::execute(std::string s) {
	string filename = "";
	string extension = "";
	istringstream iss(s);
	iss >> filename; 
	iss >> extension;
	AbstractFile* catFile = afs_ptr->openFile(filename);

	//If openFile returned a nullPtr we return a nonzero value and do not continue
	if (catFile == nullptr) {
		return fileDoesNotExist;
	}
	bool ifAppend = false;
	if (extension == "-a") {
		ifAppend = true;
	}

	//If the user wants to append they will see the contents of the file prior to input
	if (ifAppend) {
		vector<char> contents = catFile->read();
		for (char c : contents) {
			cout << c;
		}
		cout << endl; 
		cout << "Please enter the data you wish to add" << endl;
	}
	else {
		cout << "Please enter the data you wish to rewrite" << endl;
	}
	vector<char> cat_user_input;
	string input;
	bool firstIteration = true;
	while (input != ":q" && input != ":wq") {
		//Iterate through string and add each char to tentative changes
		for (char x : input) {
			cat_user_input.push_back(x);
		} 
		//Don't pushback an empty line on the first or last iteration
		getline(cin, input);
		if(!firstIteration && input!= ":q" && input != ":wq") {
			cat_user_input.push_back('\n');
		}
		else {
			firstIteration = false;
		}
	}
	//If the user quits without saving the file is simply closed without being changed
	if (input == ":q") {
		cout << "User has quit without saving" << endl;
		afs_ptr->closeFile(catFile);
		return successful;
	}
	//If the user saves and quits the file will be changed
	else if (input == ":wq") {
		cout << "User has saved and quit." << endl;
		//The append option will add to the file and return the corresponding value from calling append
		if (ifAppend) {
			int appd_result = catFile->append(cat_user_input);
			afs_ptr->closeFile(catFile);
			return appd_result;
		}
		//The user has not opted to append so the user input will become the file contents
		//The correspondong value from calling write is returned
		else {
			int write_result = catFile->write(cat_user_input);
			afs_ptr->closeFile(catFile);
			return write_result;
		}
	}
	//If the program has executed until here, the command has failed
	else {
		afs_ptr->closeFile(catFile);
		return failedCommand;
	}
}

//Command to display information bout the command to the user
void CatCommand::displayInfo() {
	cout << "The cat command can be invoked with cat <filename> to write or cat <filename> -a to append." << endl;
	cout << " Enter data you would like to append to the existing file. When done, press Enter then :wq to save the file and exit, enter :q to exist without saving." << endl;
}