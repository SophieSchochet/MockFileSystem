#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// declaration of SimpleFileSystem class goes here
#include "..\SharedCode\AbstractFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"

class SimpleFileSystem : public AbstractFileSystem {
public:
	 int addFile(std::string fileName, AbstractFile* abfile) override;
	 int deleteFile(std::string fileName) override;
	 AbstractFile* openFile(std::string fileName) override;
	 int closeFile(AbstractFile* abfile) override;
	 std::set<std::string> getFileNames() override;
private:
	std::map<std::string, AbstractFile*> systemMap;
	std::set<AbstractFile*> openSet;
};