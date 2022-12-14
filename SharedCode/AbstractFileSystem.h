#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// This file contains the AbstractFileSystem class that is inherited by the SimpleFileSystem in this program to add, delete, open, and close files in the system.
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