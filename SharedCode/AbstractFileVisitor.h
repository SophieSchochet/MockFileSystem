#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// This file contains the AbstractFileVisitor class that is inherited by other visitors in the program to allow functions to visit files.
// declaration of the file visitor interface here

#include "ImageFile.h"
#include "TextFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* tf) = 0;
	virtual void visit_ImageFile(ImageFile* imf) = 0;
};