#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// //This file declares the AbstractFileFactory class that is implemented in SimpleFileFactory to allow users to create files
// studio 18 - file factory interface declared here
#include "SimpleFileSystem.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string fileName) = 0;

};