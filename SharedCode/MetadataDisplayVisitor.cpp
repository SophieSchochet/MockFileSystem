// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	cout << "File name: " << tf->getName() << endl;
	cout << "File size: " << tf->getSize() << endl;
	cout << "File type: " << "text" << endl;
 }

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << "File name: " << imf->getName() << endl;
	cout << "File size: " << imf->getSize() << endl;
	cout << "File type: " << "image" << endl;
}