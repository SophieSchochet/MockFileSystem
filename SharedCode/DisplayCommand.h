#pragma once
#include "../../Studio16-21/SharedCode/AbstractCommand.h"
#include "../../Studio16-21/SharedCode/AbstractFileFactory.h"


class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;
public:
	DisplayCommand(AbstractFileSystem* afs_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~DisplayCommand() = default;

};