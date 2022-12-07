#pragma once

class AbstractCommand {
private:
	virtual ~AbstractCommand() = default;
public: 
	virtual int execute(std::string s) = 0;
	virtual void displayInfo() = 0;
};