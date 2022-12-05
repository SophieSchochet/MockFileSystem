#pragma once
// declaration of BasicDisplayVisitor here

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile* tf) override;
	virtual void visit_ImageFile(ImageFile* imf) override;
};