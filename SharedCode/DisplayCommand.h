#pragma once
#include "../SharedCode/AbstractCommand.h"
#include "../SharedCode/AbstractFileSystem.h"
#include "../SharedCode/BasicDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs_ptr;
	BasicDisplayVisitor* bdv_ptr;
public:
	DisplayCommand(AbstractFileSystem* afs_in, BasicDisplayVisitor* bdv_in);
	int execute(std::string s) override;
	void displayInfo() override;
	~DisplayCommand() = default;

};