// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/TextFile.h"
using namespace std;

int main()
{
	TextFile* tf = new TextFile("test.txt");
	vector<char> toWrite = {'a', 'b', 'c', 'z'};
	tf->write(toWrite);
	vector<char> readIn = tf->read();
	toWrite.push_back('y');
	tf->write(toWrite);

	vector<char> updated = tf->read();

	for (char x: readIn) {
		cout << x << " ";
	}
	cout << endl;
	for (char x : updated) {
		cout << x << " ";
	}

	return 0;
}
