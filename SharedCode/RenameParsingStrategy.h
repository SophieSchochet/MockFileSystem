//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this file is to declare the RenameParsingStrategy class

#pragma once
#include "..\SharedCode\AbstractParsingStrategy.h"
#include <sstream>


class RenameParsingStrategy: public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string to_parse) override;
};
