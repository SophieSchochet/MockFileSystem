//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This file contains the class definition of the CatDisplayParsingStrategy 

#pragma once
#include "..\SharedCode\AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>

class CatDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string to_parse) override;
};
