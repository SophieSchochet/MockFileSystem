#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"

class TextFile:public AbstractFile {
private:
	std::vector<char> file_contents;
	std::string file_name;
public:
	TextFile(std::string input_file);
	virtual void read() override;
	virtual int write(std::vector<char> writeIn) override;
	virtual int append(std::vector<char> toAdd) override;
	virtual unsigned int getSize() override;
	virtual std::string getName() override;
};
