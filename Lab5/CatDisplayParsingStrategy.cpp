#include "CatDisplayParsingStrategy.h"


using namespace std;

vector<string> CatDisplayParsingStrategy::parse(string to_parse) {
	vector<string> to_return = {};
	string inputs;
	istringstream iss(inputs);
	string first;
	string catArgs;
	string dsArgs;

	if (!(iss >> first)) {
		return to_return;
	}

	string second; 
	if (iss >> second) { //If this succeeds, there are at least two args, meaning extension for at least one command
		string third; 
		if (iss >> third) { //If this succeeds, there are 3 args, meaning extension for both commands
			string name = third;
			catArgs = first + " " + name;
			dsArgs = second + " " + name;
		}
		else {
			string name = second; 
			if (first == "-a") {
				catArgs = first + " " + name;
				dsArgs = name;
			}
			else {
				catArgs = name;
				dsArgs = first + " " + name; 
			}
		}

	}
	to_return.push_back(catArgs);
	to_return.push_back(dsArgs);

	return to_return;
}