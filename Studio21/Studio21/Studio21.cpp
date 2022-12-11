// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\SharedCode\CommandPrompt.h"
#include "..\..\SharedCode\TouchCommand.h"
#include "..\..\SharedCode\SimpleFileFactory.h"

int main()
{
	SimpleFileSystem testSystem = SimpleFileSystem();
	SimpleFileFactory testFactory = SimpleFileFactory();
	CommandPrompt testPrompt = CommandPrompt();
	TouchCommand testTouch = TouchCommand(&testSystem, &testFactory);
	testPrompt.addCommand("touch", &testTouch);
	testPrompt.run();
	return successful;

}

