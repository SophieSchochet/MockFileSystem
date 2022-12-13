// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include <string>
#include<iostream>
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string fileName) {
	if (fileName.size() > 4) {
		//Invalid file name if it contains a space
		if (fileName.find(" ")<fileName.length()) {
			return nullptr;
		}
		string extension = fileName.substr(fileName.size() - 4, fileName.size() - 1);
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