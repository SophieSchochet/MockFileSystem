// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\SimpleFileFactory.h"
using namespace std;

int main()
{
	AbstractFileSystem* sfs_ptr = new SimpleFileSystem();
	AbstractFileFactory* sff_ptr = new SimpleFileFactory();
	AbstractFile* tester = sff_ptr->createFile("newFile.txt");
	sfs_ptr->addFile("newFile.txt", tester);
	AbstractFile* test2 = sfs_ptr->openFile("newFile.txt");
	vector<char> newVect = { 'T', 'E', 'S', 'T' };
	test2->write(newVect);
	test2->read();
	return 0;
}
