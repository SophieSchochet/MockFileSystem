// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\SimpleFileSystem.h"


using namespace std;


int main()
{	
	SimpleFileSystem sfs = SimpleFileSystem(); 
	TextFile tf1 = TextFile("tf1.txt");
	ImageFile tf2 = ImageFile("tf2.img");
	sfs.addFile("tf1.txt", tf1);

	sfs.createFile("test1.txt");
	sfs.createFile("test2.img");
	sfs.createFile("test3");

}

