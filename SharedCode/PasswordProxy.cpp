#include "PasswordProxy.h"
#include "AbstractFileVisitor.h"
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* in_ptr, string in_pswd) : af_ptr(in_ptr), pswd(in_pswd) {}

PasswordProxy :: ~PasswordProxy() {
	delete this->af_ptr;
}

string PasswordProxy::passwordPrompt() {
	cout << "Please enter a password" << endl;
	string input;
	cin>>input;
	return input;
}

bool PasswordProxy::check_match(std::string str_guess) {
	if (str_guess == this->pswd) {
		return true;
	}
	return false;
}

vector<char> PasswordProxy::read() {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->read();
	}

	vector<char> toReturn = {};
	return toReturn;

}

 int PasswordProxy::write(vector<char> to_write) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->write(to_write);
	}
	return incorrectPassword;
}

int PasswordProxy::append(vector<char> to_add) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->append(to_add);
	}
	return incorrectPassword;
}

unsigned int PasswordProxy::getSize() {
	return af_ptr->getSize();
}

string PasswordProxy::getName() {
	return af_ptr->getName();
}

void PasswordProxy ::accept(AbstractFileVisitor* afv) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		af_ptr->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(string newName) {

	return new PasswordProxy(af_ptr->clone(newName),pswd);
}
