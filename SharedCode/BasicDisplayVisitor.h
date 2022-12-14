#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// declaration of BasicDisplayVisitor here
//This file contains the declaration of the BasicDisplayVisitor class that inherits publicly from the AbstractFileVisitor class

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile* tf) override;
	virtual void visit_ImageFile(ImageFile* imf) override;
};