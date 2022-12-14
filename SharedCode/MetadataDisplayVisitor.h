#pragma once
//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
// declaration of MetadataDisplayVisitor here

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
	int displayLength = 20;
	virtual void visit_TextFile(TextFile* tf) override;
	virtual void visit_ImageFile(ImageFile* imf) override;
};
