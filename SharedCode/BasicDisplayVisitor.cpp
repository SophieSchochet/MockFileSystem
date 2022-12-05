// definitions of basic display visitor here

#include "BasicDisplayVisitor.h"

using namespace std; 

void BasicDisplayVisitor::visit_TextFile(TextFile* tf) {
	for (char c : tf->read()) {
		cout << c;
	}
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	for (int i = imf->size - 1; i >= 0; i--) {
		for( int j = 0; j < imf->size; j++) {
		cout << imf->read()[imf->getIndexFromCoords(j, i)];
		}
	cout << endl;
	}
}