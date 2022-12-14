#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// Image file class declaration here


#include "AbstractFile.h"



class ImageFile: public AbstractFile {
	friend class BasicDisplayVisitor;
public:
	ImageFile(std::string inName);
	std::vector<char> read() override;
	int write(std::vector<char> writeIn) override;
	int append(std::vector<char> toAdd) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* afv) override;
	AbstractFile* clone(std::string newName) override;


private:
	int getIndexFromCoords(int x, int y);
	std::string name;
	std::vector<char> contents;
	char size;
	
};


