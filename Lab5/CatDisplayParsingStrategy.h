#pragma once
#include "..\SharedCode\AbstractParsingStrategy.h"
#include <sstream>
#include <iostream>

class CatDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string to_parse) override;
};
