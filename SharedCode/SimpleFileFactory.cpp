// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string fileName) {
	if (fileName.size() > 4) {
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