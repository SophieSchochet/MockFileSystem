//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This file contains the definition of the LSCommand class 
#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "MetadataDisplayVisitor.h"

class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;
	MetadataDisplayVisitor* mdv_ptr;
public: 
	LSCommand(AbstractFileSystem* afs_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~ LSCommand() = default;
	
};