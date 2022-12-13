#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/BasicDisplayVisitor.h"
#include <sstream>

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;
	BasicDisplayVisitor* bdv_ptr;
public:
	DisplayCommand(AbstractFileSystem* afs_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~DisplayCommand() = default;

};