// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\SharedCode\RenameParsingStrategy.h"
#include "..\..\SharedCode\MacroCommand.h"
#include "..\..\SharedCode\RemoveCommand.h"
#include "..\..\SharedCode\CopyCommand.h"
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\CommandPrompt.h"
#include"..\..\SharedCode\TouchCommand.h"
#include "..\..\SharedCode\DisplayCommand.h"
#include "..\..\SharedCode\CatCommand.h"
#include "..\..\SharedCode\LSCommand.h"
#include "..\CatDisplayParsingStrategy.h"



int main()
{
	SimpleFileFactory sff = SimpleFileFactory();
	SimpleFileSystem sfs = SimpleFileSystem();
	CommandPrompt cmd_prmpt = CommandPrompt();
	RemoveCommand rem = RemoveCommand(&sfs);
	CopyCommand cpy = CopyCommand(&sfs);
	RenameParsingStrategy rps = RenameParsingStrategy();
	MacroCommand mac_cmd = MacroCommand(&sfs);
	TouchCommand tc = TouchCommand(&sfs, &sff);
	DisplayCommand dc = DisplayCommand(&sfs);
	CatCommand cat_cmd = CatCommand(&sfs);
	LSCommand ls_cmd = LSCommand(&sfs);
	CatDisplayParsingStrategy cat_ds_parse = CatDisplayParsingStrategy();


	//Macro command support 
	//We added support for cat + ds to make changes and immediately display them
	MacroCommand cat_ds = MacroCommand(&sfs); 
	cat_ds.addCommand(&cat_cmd);
	cat_ds.addCommand(&dc);
	cat_ds.setParseStrategy(&cat_ds_parse);


	mac_cmd.addCommand(&cpy);
	mac_cmd.addCommand(&rem);
	mac_cmd.setParseStrategy(&rps);


	cmd_prmpt.addCommand("cads", &cat_ds);
	cmd_prmpt.addCommand("ls", &ls_cmd);
	cmd_prmpt.addCommand("cat", &cat_cmd);
	cmd_prmpt.addCommand("ds", &dc);
	cmd_prmpt.addCommand("rm", &rem);
	cmd_prmpt.addCommand("cp", &cpy);
	cmd_prmpt.addCommand("rn", &mac_cmd);
	cmd_prmpt.addCommand("touch", &tc);
	

	cmd_prmpt.run();
	return 0;
}


