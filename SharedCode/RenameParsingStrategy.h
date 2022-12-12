#pragma once
#include "..\SharedCode\AbstractParsingStrategy.h"
#include <sstream>


class RenameParsingStrategy: public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string to_parse) override;
};
