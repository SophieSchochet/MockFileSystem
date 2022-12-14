//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"

using namespace std;

//Adds a file to the system by creating a file and inserting it into map
//Returns either 0 to indicate success or a nonzero value corresponding to an error encountered
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
//If the file could be opened, a pointer to the file is returned, otherwise nullptr is retured
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

//Gets the names of all files in the system and returns a set of the names
set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;
	for (auto& x : systemMap) {
		fileNames.insert(x.first);
	}
	return fileNames;
}

//Closes a file by removing it from open file set
//Returns either 0 to indicate success or a nonzero value corresponding to the error encountered
int SimpleFileSystem::closeFile(AbstractFile* inFile) {
	if (openSet.count(inFile) > 0) {
		openSet.erase(inFile);
		return successful;
	}
	return fileNotOpen;
}

//Deletes a file if it exists by removing from system and deleting pointer
//Returns 0 to indicate success or a nonzero return value corresponding to the error encountered
int SimpleFileSystem::deleteFile(string fileName) {

	//checks to see if it is found in the system map
	if (systemMap.count(fileName) == 0) {
		return fileDoesNotExist;
	}
	//checks to see if the file is currently open
	if (openSet.count(systemMap.at(fileName)) > 0) {
		return fileAlreadyOpen;
	}
	//if the program executes to here, the file can be deleted
	AbstractFile* ptr = systemMap.at(fileName);
	systemMap.erase(fileName);
	delete ptr;
	return successful;
	
}
