#pragma once

#pragma once

#include<vector>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> commands;
	AbstractParsingStrategy* aps_ptr;
public:
	MacroCommand();
	~MacroCommand() = default;
	void displayInfo() override;
	int execute(std::string s) override;
	void addCommand(AbstractCommand* ab_cmd_ptr);
	void setParseStrategy(AbstractParsingStrategy* aps_ptr_in);
};

