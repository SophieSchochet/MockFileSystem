//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This file contains the declaration of the CopyCommand class that inherits publicly from the AbstractCommand class
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include <sstream>


class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;

public:
	CopyCommand(AbstractFileSystem* afs_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~CopyCommand() = default;

};