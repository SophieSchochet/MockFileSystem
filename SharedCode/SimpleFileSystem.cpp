// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

using namespace std;

//Adds a file to the system by creating a file and inserting it into map
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

//Opens a file by adding it to the open set
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

//Gets the names of all files in the system
set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;
	for (auto& x : systemMap) {
		fileNames.insert(x.first);
	}
	return fileNames;
}

//Closes a file by removing it from open file set
int SimpleFileSystem::closeFile(AbstractFile* inFile) {
	if (openSet.count(inFile) > 0) {
		openSet.erase(inFile);
		return successful;
	}
	return fileNotOpen;
}

//Deletes a file if it exists by removing from system and deleting pointer
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
