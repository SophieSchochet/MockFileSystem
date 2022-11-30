#pragma once
// studio 18 - file factory interface declared here
#include "SimpleFileSystem.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string fileName) = 0;

};