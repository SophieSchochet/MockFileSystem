//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// definition of ImageFile class here

#include "ImageFile.h"

#include "AbstractFileVisitor.h"

using namespace std;

//Constructor for an Image file, sets the name of the file to the name passed in by the user
ImageFile::ImageFile(string inName) {
	name = inName;
	size = 0;
}

//Returns the size of the file contents
unsigned int ImageFile::getSize() {
	return contents.size();
}

//Returns the name of the file
string ImageFile::getName() {
	return this->name;
}

//Takes in user input and makes it the file contents
//Returns 0 to indicate success or a nonzero return value corresponding to the error encountered

int ImageFile::write(vector<char> inputs) {
	size = inputs[inputs.size() - 1] - '0';
	inputs.pop_back();


	if ((size * size) != inputs.size()) {
		return sizeMismatch;
	}
	
//Ensures the user has inputted valid input and places it in the file contents if it is valid
	for (char x : inputs) {
		if (x != ' ' && x != 'X') {
			contents.clear();
			size = 0;
			return incorrectImageFileInput;
		}
		contents.push_back(x);
	}
	return successful;
}

//Returns a nonzero value corresponding to an error bacause ImageFiles do not support the append function
int ImageFile::append(vector<char> toAppend) {
	return appendNotAvailable;
}

//Returns the contents of the image file
vector<char> ImageFile::read() {
	return contents;
}

//Helper method to calculate indecies and properly display images
int ImageFile::getIndexFromCoords(int x, int y) {
	return y * size + x;
}

//Allows ImageFiles to be visited by various visitors
void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_ImageFile(this);
}

//Defines the clone method for an ImageFile, returns the clone created
AbstractFile* ImageFile::clone(string newName) {
	newName += "img";
	ImageFile* newFile = new ImageFile(newName);
	newFile->contents = this->contents;
	return newFile;
}