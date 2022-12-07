#include "CommandPrompt.h"
using namespace std;


CommandPrompt::CommandPrompt() : afs(nullptr), aff(nullptr) {}

void CommandPrompt ::setFileSystem(AbstractFileSystem* afs_in) {
	 afs = afs_in;
}


void CommandPrompt::setFileFactory(AbstractFileFactory* aff_in) {
	 aff = aff_in;
}

int CommandPrompt::addCommand(std::string s, AbstractCommand* ac_in) {
	
	if (cmd_map.insert({ s, ac_in }).second) {
		return success;
	}

	return cannotAddCommand;
}


int  CommandPrompt:: run() {
	while (true) {
		string input = prompt();
		if (input == "q") {
			return userQuit;
		} else if (input == "help") {
			listCommands();
		}
		else if (input.find(' ') < input.length()) {
			bool found = false;
			for (auto const& x : cmd_map) {
				if (x.first == input) {
					found = true;
					if (x.second->execute("") != 0) {
						cout << "Command failed";
					}
				}
			}
			if (!found) {
				cout << "Command not found";
			}
		}
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
					cout << "Command not found";
				}

			}
			else {
				bool found = false;
				for (auto const& x : cmd_map) {
					if (x.first == first) {
						found = true;
						string info = input.substr(first.length());
						if (x.second->execute(info) != 0) {
							cout << "Command failed";
						}
					}
				}
				if (!found) {
					cout << "Command not found";
				}
			}
			
		}
	}
}

void CommandPrompt :: listCommands() {
	/*map<string, AbstractCommand*> ::iterator it;
	for (it = cmd_map.begin(); it != cmd_map.end(); ++it) {

	}*/

	for (auto const& x : cmd_map) {
		cout << x.first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Please input a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command" << endl;
	cout << "$   ";
	string user_command;
	getline(cin, user_command);
	return user_command;
}