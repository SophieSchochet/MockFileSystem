// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\SimpleFileSystem.h"


using namespace std;


int main()
{	
	SimpleFileSystem sfs = SimpleFileSystem(); 
	TextFile tf1 = TextFile("tf1.txt");
	ImageFile tf2 = ImageFile("tf2.img");
	sfs.addFile("tf1.txt", &tf1);
	sfs.addFile("tf2.img", &tf2);
	sfs.createFile("test2.img");
	sfs.createFile("test3");
	sfs.openFile("tf1.txt");
	sfs.deleteFile("tf2.img");

}

