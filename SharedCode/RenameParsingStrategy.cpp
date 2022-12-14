//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the function parse within the RenameParsingStrategy class
#include "..\SharedCode\RenameParsingStrategy.h"

using namespace std;

//Wraps the string parameter in a stream, extracts the existing file and its new name if possible
//Creates a vector of the initial input followed by the existing file and returns it
vector<string> RenameParsingStrategy::parse(string to_parse) {
	vector<string> to_return;
	string existing_file;
	string new_name;
	istringstream iss(to_parse);
	iss >> existing_file;
	iss >> new_name;
	to_return.push_back(to_parse);
	to_return.push_back(existing_file);
	return to_return;
}