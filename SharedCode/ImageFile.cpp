// definition of ImageFile class here

#include "ImageFile.h"

#include "AbstractFileVisitor.h"

using namespace std;

ImageFile::ImageFile(string inName) {
	name = inName;
	size = 0;
}

unsigned int ImageFile::getSize() {
	return contents.size();
}

string ImageFile::getName() {
	return this->name;
}

int ImageFile::write(vector<char> inputs) {
	size = inputs[inputs.size() - 1] - '0';
	inputs.pop_back();

	if ((size * size) != inputs.size()) {
		return sizeMismatch;
	}
	/*
	if (size < 0 || size > 9) {
		return incorrectImageFileInput;
	} */
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

int ImageFile::append(vector<char> toAppend) {
	return appendNotAvailable;
}

vector<char> ImageFile::read() {
	return contents;
}


int ImageFile::getIndexFromCoords(int x, int y) {
	return y * size + x;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(string newName) {
	newName += "img";
	ImageFile* newFile = new ImageFile(newName);
	newFile->contents = this->contents;
	return newFile;
}