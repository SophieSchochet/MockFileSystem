#include "..\SharedCode\RenameParsingStrategy.h"

using namespace std;

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