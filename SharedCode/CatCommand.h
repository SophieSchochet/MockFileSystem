#pragma once
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"


class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;

public:
	CatCommand(AbstractFileSystem* afs_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~CatCommand() = default;

};