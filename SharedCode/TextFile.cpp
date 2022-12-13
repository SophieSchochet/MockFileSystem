//  Define the TextFile class here
#include "TextFile.h"

#include "AbstractFileVisitor.h"

using namespace std;

TextFile::TextFile(string input_file) {
	file_name = input_file;
}

vector<char> TextFile::read() {
	return file_contents;
}

unsigned int TextFile::getSize() {
	return file_contents.size();
}

string TextFile::getName() {
	return file_name;
}

int TextFile::write(vector<char> writeIn) {
	file_contents = writeIn;
	return successful;
}

int TextFile::append(std::vector<char> toAdd) {
	for (char c : toAdd) {
		file_contents.push_back(c);
	}
	return successful;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_TextFile(this);
}

AbstractFile* TextFile::clone(string newName) {
	newName += ".txt";
	return new TextFile(newName);
}
