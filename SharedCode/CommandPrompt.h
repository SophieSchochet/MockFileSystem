#pragma once
#include "AbstractFileFactory.h"
#include "AbstractCommand.h"
#include <sstream> 
#include <iostream>
class CommandPrompt {
private:
	std::map <std::string, AbstractCommand*> cmd_map;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
public:
	CommandPrompt();
	~CommandPrompt() = default;
	void setFileSystem(AbstractFileSystem* afs_in);
	void setFileFactory(AbstractFileFactory* aff_in);
	int addCommand(std::string s, AbstractCommand* ac_in);
	int run();
protected:
	void listCommands();
	std::string prompt();
};