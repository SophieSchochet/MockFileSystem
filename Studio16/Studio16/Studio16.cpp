// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>

using namespace std;


int main()
{

	TextFile file = TextFile("tester");
	AbstractFile* filePtr = &file;
	vector<char> writeIn;
	writeIn.push_back('h');
	writeIn.push_back('i');
	filePtr->write(writeIn);
	cout << "Reading..." << endl;
	filePtr->read();
	return 0;
}


