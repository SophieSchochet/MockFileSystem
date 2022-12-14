#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"

class SimpleFileFactory: public AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string fileName) override;
};