// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile* inFile) {
	if (systemMap.count(fileName)!=0) {
		return duplicateFile;
	}
	if (inFile == nullptr) {
		return nullFile;
	}
	systemMap.insert(make_pair(fileName, inFile));
	return successful;
}

AbstractFile* SimpleFileSystem::openFile(string fileName) {
	if (systemMap.count(fileName) == 0) {
		return nullptr;
	}
	if (openSet.count(systemMap.at(fileName)) > 0) {
		return nullptr;
	}
	openSet.insert(systemMap.at(fileName));
	return systemMap.at(fileName);
}

int SimpleFileSystem::closeFile(AbstractFile* inFile) {
	if (openSet.count(inFile) > 0) {
		openSet.erase(inFile);
		return successful;
	}
	return fileNotOpen;
}

int SimpleFileSystem::deleteFile(string fileName) {
	if (systemMap.count(fileName) == 0) {
		return fileDoesNotExist;
	}
	if (openSet.count(systemMap.at(fileName)) > 0) {
		return fileAlreadyOpen;
	}
	AbstractFile* ptr = systemMap.at(fileName);
	systemMap.erase(fileName);
	delete ptr;
	return successful;
	
}
