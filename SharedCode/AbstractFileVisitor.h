#pragma once
// declaration of the file visitor interface here

#include "ImageFile.h"
#include "TextFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* tf) = 0;
	virtual void visit_ImageFile(ImageFile* imf) = 0;
};