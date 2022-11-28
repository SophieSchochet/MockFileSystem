#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
#include <vector>
#include <iostream>
#include<string>
#include <map>
#include <set>

class AbstractFile {
public:
	virtual void read()=0;
	virtual int write(std::vector<char> writeIn)=0;
	virtual int append(std::vector<char> toAdd)=0;
	virtual unsigned int getSize()=0;
	virtual std::string getName()=0;
	virtual ~AbstractFile() = default;
};


enum errors {success, incorrectImageFileInput, appendNotAvailable, sizeMismatch, 
	duplicateFile, nullFile, duplicateFileName, invalidFileName, invalidExtension,
	fileNotOpen, fileDoesNotExist, fileAlreadyOpen};