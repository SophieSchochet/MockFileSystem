// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	if (tf != nullptr) {
		cout << setw(20);
		cout << "File name: " << tf->getName();
		cout << "File type: " << "text";
		cout << "File size: " << tf->getSize() << endl;
	}

 }

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << setw(20);
	cout << imf->getName();
	cout << "image";
	cout << imf->getSize() << endl;
}