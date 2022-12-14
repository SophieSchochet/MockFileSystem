//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//  Define the TextFile class here
#include "TextFile.h"

#include "AbstractFileVisitor.h"

using namespace std;

//Constructor to create a textFile with a given name
TextFile::TextFile(string input_file) {
	file_name = input_file;
}

//returns the contents of the file
vector<char> TextFile::read() {
	return file_contents;
}

//returns the size of the file contents
unsigned int TextFile::getSize() {
	return file_contents.size();
}

//returns the name of the file
string TextFile::getName() {
	return this->file_name;
}

//sets the contents of the file to the passed in parameter and returns 0 to indicate success once complete
int TextFile::write(vector<char> writeIn) {
	file_contents = writeIn;
	return successful;
}

//Adds the given parameter to the file contents and returns 0 to indicate success once complete
int TextFile::append(std::vector<char> toAdd) {
	for (char c : toAdd) {
		file_contents.push_back(c);
	}
	return successful;
}

//Allows TextFiles to be visited by various visitors
void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_TextFile(this);
}

//Adds the corresponding extension to the file name, creates a new file with the given name and the contents of the old one, and returns the clone
AbstractFile* TextFile::clone(string newName) {
	newName += ".txt";
	TextFile* newFile = new TextFile(newName);
	newFile->file_contents = this->file_contents;

	return newFile;
}
