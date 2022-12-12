#include "CatCommand.h"
using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_in) {
	afs_ptr = afs_in;
}


int CatCommand::execute(std::string s) {

}


void CatCommand::displayInfo() {
	cout<<
}