//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This program allows the user to input various commands and interact with the file system

#include "CommandPrompt.h"
using namespace std;


CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {}

void CommandPrompt ::setFileSystem(AbstractFileSystem* afs_in) {
	 afs = afs_in;
}


void CommandPrompt::setFileFactory(AbstractFileFactory* aff_in) {
	 aff = aff_in;
}

//addCommand inserts a given command into the command map and either returns 0 to indicate sucess or a corresponding nonzero failure value
int CommandPrompt::addCommand(std::string s, AbstractCommand* ac_in) {
	
	if (cmd_map.insert({ s, ac_in }).second) {
		return successful;
	}

	return cannotAddCommand;
}

//This function will run continuously until the user chooses to quit;
int  CommandPrompt:: run() {

	while (true) {
		string input = prompt();
		if (input == "q") {
			cout << "User has Quit." << endl;
			return userQuit;
		} 
		else if (input == "help") {
			listCommands();
		}
		
		else if (! (input.find(' ') < input.length())) { //No space is found, so command is only one word
			bool found = false;
			for (auto const& x : cmd_map) { //Search for the command in the map
				if (x.first == input) {
					found = true;
					if (x.second->execute("") != 0) { //Call execute with no input
						cout << "Command failed" << endl;
					}
				}
			}
			if (!found) {
				cout << "Command not found" << endl;
			}
		}
		//If the first word is help and the second word is a valid command name, information on that command is displayed to the user
		else {
			stringstream iss(input);
			string first;
			iss >> first;
			if (first == "help") {
				string second;
					iss >> second;
				bool found = false;
				for (auto const& x : cmd_map) {
					if (x.first == second) {
						found = true;
						x.second->displayInfo();
					}
				}
				if (!found) {
					cout << "Command not found" << endl;
				}

			}
			//Checks to see if the first word extracted is a valid command name, passing the remainder of the string into the execute parameters
			else {
				bool found = false;
				for (auto const& x : cmd_map) {
					if (x.first == first) {
						found = true;
						string info = input.substr(first.length() +1);
						if (x.second->execute(info) != successful) {
							cout << "Command failed" << endl;
						}
					}
				}
				if (!found) {
					cout << "Command not found" << endl;;
				}
			}
			
		}
	}
}

//Print out all the commands that are available
void CommandPrompt :: listCommands() {
	for (auto const& x : cmd_map) {
		cout << x.first << endl;
	}
}

//Prompt the user to enter a command. Simulates a real terminal.
string CommandPrompt::prompt() {
	cout << "Please input a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command" << endl;
	cout << "$   ";
	string user_command;
	getline(cin, user_command);
	return user_command;
}