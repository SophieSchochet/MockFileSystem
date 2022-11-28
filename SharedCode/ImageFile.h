#pragma once
// Image file class declaration here


#include "AbstractFile.h"

class ImageFile: public AbstractFile {
public:
	ImageFile(std::string inName);
	void read() override;
	int write(std::vector<char> writeIn) override;
	int append(std::vector<char> toAdd) override;
	unsigned int getSize() override;
	std::string getName() override;
private:
	std::string name;
	std::vector<char> contents;
	char size;
	int getIndexFromCoords(int x, int y);
	
};


