#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
	AbstractFileSystem* afs_ptr;
	

public:
	RemoveCommand(AbstractFileSystem* afs_in);
	~RemoveCommand() = default;

	void displayInfo() override;
	int execute(std::string s) override;
};
