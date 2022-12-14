//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include <string>
#include<iostream>
using namespace std;

//createFile creates a new file given a file name and returns either a pointer to the new file or nullptr if the file could not be created
AbstractFile* SimpleFileFactory::createFile(string fileName) {
	if (fileName.size() > 4) {
		//Invalid file name if it contains a space
		if (fileName.find(" ")<fileName.length()) {
			return nullptr;
		}
		//Looks at the file extension and creates either a textFile for ".txt" or imageFile for ".img"
		string extension = fileName.substr(fileName.size() - 4, 4);
		if (extension == ".txt") {
			return new TextFile(fileName);
		}
		else if (extension == ".img") {
			return new ImageFile(fileName);
		}
		return nullptr;
	}
		return nullptr;

}