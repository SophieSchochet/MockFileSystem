// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
	cout << setw(20);
	cout << "File name: " << tf->getName();
	cout << "File type: " << "text";
	cout << "File size: " << tf->getSize() << endl;
 }

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << setw(20);
	cout << "File name: " << imf->getName();
	cout << "File type: " << "image";
	cout << "File size: " << imf->getSize() << endl;
}