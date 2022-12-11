#pragma once
// declaration of the interface all file systems provide goes here
#include "AbstractFile.h"



class AbstractFileSystem {
public:
	virtual int addFile(std::string fileName, AbstractFile* abfile) = 0;
	virtual int deleteFile(std::string fileName) = 0;
	virtual AbstractFile* openFile(std::string fileName) = 0;
	virtual int closeFile(AbstractFile* abfile) = 0;
	virtual std::set<std::string> getFileNames() = 0;
};