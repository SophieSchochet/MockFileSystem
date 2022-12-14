//Authors: Ellie Ertl, Sophie Schochet, Veda Bhalla
//The purpose of this program is to define the functions of the PasswordProxy class
#include "PasswordProxy.h"
#include "AbstractFileVisitor.h"
using namespace std;

//Constrcutor to create  a password proxy given a pointer to an AbstractFile and the password to protect it with
PasswordProxy::PasswordProxy(AbstractFile* in_ptr, string in_pswd) : af_ptr(in_ptr), pswd(in_pswd) {}

PasswordProxy :: ~PasswordProxy() {
	delete this->af_ptr;
}

//Prompts the user for a password and returns their input
string PasswordProxy::passwordPrompt() {
	cout << "Please enter a password" << endl;
	string input;
	getline(cin, input);
	return input;
}

//Checks to see if the user input matches the PasswordProxy password, returns true if it does and false if it doesn't
bool PasswordProxy::check_match(std::string str_guess) {
	if (str_guess == this->pswd) {
		return true;
	}
	return false;
}

//Prompts the user for a password and if it is correct, calls read on the actual file
//Returns either the contents of the file or an empty vector if password incorrect
vector<char> PasswordProxy::read() {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->read();
	}

	vector<char> toReturn;
	return toReturn;

}
//Prompts the user for a password and if it is correct, calls write on the actual file
//Returns either the results of calling write on the file or the nonzero value indicating an incorrect password
 int PasswordProxy::write(vector<char> to_write) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->write(to_write);
	}
	return incorrectPassword;
}

 //Prompts the user for a password and if it is correct, calls append on the actual file
 //Returns either the results of callung append on the file or a nonzero value indicating an incorrect password
int PasswordProxy::append(vector<char> to_add) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		return af_ptr->append(to_add);
	}
	return incorrectPassword;
}

//Returns the size of the file
unsigned int PasswordProxy::getSize() {
	return af_ptr->getSize();
}

//Returns the name of the file
string PasswordProxy::getName() {
	return af_ptr->getName();
}

//Prompts the user for a password and if it is correct, calls accept on the file, allowing it to be visited
void PasswordProxy ::accept(AbstractFileVisitor* afv) {
	string in_password = passwordPrompt();
	if (check_match(in_password)) {
		af_ptr->accept(afv);
	}
}

//Clones the file, then creates and returns a new password proxy for the newly created file using the same password as the old one
AbstractFile* PasswordProxy::clone(string newName) {

	return new PasswordProxy(af_ptr->clone(newName),pswd);
}
