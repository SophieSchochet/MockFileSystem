#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//This file contains the AbstractParsingStrategy class declaration
#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string to_parse) = 0;
};
