#pragma once
#include "AbstractFile.h"
class AbstractFileVistor;

class PasswordProxy : public AbstractFile {
private:
	AbstractFile* af_ptr;
	std::string pswd;
public:

	PasswordProxy(AbstractFile* in_ptr, std::string in_pswd);
	~PasswordProxy();
	std::vector<char> read() override;
	int write(std::vector<char> to_write) override;
	int append(std::vector<char> to_add) override;
	unsigned int getSize() override;
	std::string getName() override;
	void accept(AbstractFileVisitor* afv) override;

protected:
	std::string passwordPrompt();
	bool check_match(std::string str_guess);
};