#include "MacroCommand.h"


using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs_ptr_in) {
	afs_ptr = afs_ptr_in;
}


//Takes a pointer to an AbstractCommand and pushes it to the end of member variable commands vector
void MacroCommand::addCommand(AbstractCommand* ab_cmd_ptr) {
	commands.push_back(ab_cmd_ptr);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_ptr_in) {
	aps_ptr = aps_ptr_in;
}

//Take output from parsing strategy and individually execute each command
int MacroCommand::execute(string s) {
	vector<string> inputs = aps_ptr->parse(s);
	int cmdSuccess = successful;
	for (int i = 0; i < commands.size(); i++) {
		AbstractCommand* cmd = commands[i];
		cmdSuccess += cmd->execute(inputs[i]);
	}
	if (cmdSuccess != successful) {
		return failedCommand;
	}
	else {
		return successful;
	}

}

void MacroCommand::displayInfo() {
	cout << "A macroCommand is a combination of two commands." << endl;
}
