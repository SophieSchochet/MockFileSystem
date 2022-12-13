// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include <iomanip>


using namespace std;

void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
		cout << setw(displayLength)<< tf->getName();
		cout << setw(displayLength) << "text";
		cout << setw(displayLength) << tf->getSize() << endl;
 }

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << setw(displayLength) << imf->getName();
	cout << setw(displayLength) << "image";
	cout << setw(displayLength) <<  imf->getSize() << endl;
}