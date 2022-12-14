//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// definitions of metadata visitor here

#include "MetadataDisplayVisitor.h"
#include <iomanip>


using namespace std;

//Displays the metadata of a text file when given a pointer to a text tfile
void MetadataDisplayVisitor::visit_TextFile(TextFile* tf) {
		cout << setw(displayLength)<< tf->getName();
		cout << setw(displayLength) << "text";
		cout << setw(displayLength) << tf->getSize() << endl;
 }

//Displays the metadata of an image file when given a pointer to an image file
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* imf) {
	cout << setw(displayLength) << imf->getName();
	cout << setw(displayLength) << "image";
	cout << setw(displayLength) <<  imf->getSize() << endl;
}