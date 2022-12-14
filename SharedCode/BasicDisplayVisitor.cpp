// definitions of basic display visitor here
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define a display visitor for both text and image files 

#include "BasicDisplayVisitor.h"

using namespace std; 

//Text files can simply be read back out
void BasicDisplayVisitor::visit_TextFile(TextFile* tf) {
	for (char c : tf->read()) {
		cout << c;
	}
}

//Image files require formatting, we use the getIndexFromCoords helper function to properly display the image
void BasicDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	for (int i = imf->size - 1; i >= 0; i--) {
		for( int j = 0; j < imf->size; j++) {
		cout << imf->read()[imf->getIndexFromCoords(j, i)];
		}
	cout << endl;
	}
}