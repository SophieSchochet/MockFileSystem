#pragma once
// declaration of SimpleFileSystem class goes here
#include "..\SharedCode\AbstractFileSystem.h"
#include "ImageFile.h"
#include "TextFile.h"

class SimpleFileSystem : public AbstractFileSystem {
public:
	 int addFile(std::string fileName, AbstractFile* abfile) override;
	 int createFile(std::string fileName) override;
	 int deleteFile(std::string fileName) override;
	 AbstractFile* openFile(std::string fileName) override;
	 int closeFile(AbstractFile* abfile) override;
private:
	std::map<std::string, AbstractFile*> systemMap;
	std::set<AbstractFile*> openSet;
};