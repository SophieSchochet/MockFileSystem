#pragma once
// declaration of MetadataDisplayVisitor here

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
	virtual void visit_TextFile(TextFile* tf) override;
	virtual void visit_ImageFile(ImageFile* imf) override;
};
