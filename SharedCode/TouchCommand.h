//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//Thsi file contains the declaration of the TouchCommand class
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include <sstream>
class TouchCommand : public AbstractCommand {
	AbstractFileSystem* afs_ptr;
	AbstractFileFactory* aff_ptr;

public:
	TouchCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in);
	~TouchCommand() = default;

	void displayInfo() override;
	int execute(std::string s) override;
};