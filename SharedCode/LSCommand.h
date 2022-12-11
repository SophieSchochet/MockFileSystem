#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"


class LSCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;
	AbstractFileFactory* aff_ptr;
public: 
	LSCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~ LSCommand() = default;
	
};