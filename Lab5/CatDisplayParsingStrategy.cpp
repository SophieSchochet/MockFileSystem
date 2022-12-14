#include "CatDisplayParsingStrategy.h"
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// The purpose of this file is to define the parsing strategy for the cads command to be implemented by the program
//Format of command: cads <filename> [-a] [-d]

using namespace std;

vector<string> CatDisplayParsingStrategy::parse(string to_parse) {
	vector<string> to_return = {};
	string inputs;
	istringstream iss(to_parse);
	string first;
	string catArgs;
	string dsArgs;
	string name;

	//if you cannot extract an argument, return an empty vector
	if (!(iss >> first)) {
		return to_return;
	}
	else {
		name = first; 
	}

	string second; 
	if (iss >> second) { //If this succeeds, there are at least two args, meaning extension for at least one command
		cout << "Got second" << endl;
		string third; 
		if (iss >> third) { //If this succeeds, there are 3 args, meaning extension for both commands
			cout << "Got third" << endl;
			catArgs = name + " " + second;
			dsArgs = name + " " + third;
		}
		else { //If there are ONLY two args: 
			if (second == "-a") {  //If the first is -a, this must go with cat command.
				catArgs = name + " " + second;
				dsArgs = name;
			}
			else { //If the first is not -a, it would go with ds command. Note: only valid input in this case is -d, but we don't need to check that because the command will just fail otherwise. 
				catArgs = name;
				dsArgs = name + " " + second; 
			}
		}

	}
	else { //If there's only one argument, we pass name to both. 
		catArgs = name;
		dsArgs = name;
	}

	to_return.push_back(catArgs);
	to_return.push_back(dsArgs);

	//return the final vector of arguments
	return to_return;
}