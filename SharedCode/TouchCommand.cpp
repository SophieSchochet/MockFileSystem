#include "..\SharedCode\TouchCommand.h"
#include "..\SharedCode\PasswordProxy.h"
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs_in, AbstractFileFactory* aff_in) {
	afs_ptr = afs_in;
	aff_ptr = aff_in;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch <fileName>" << endl;
}

int TouchCommand::execute(string s) {
	AbstractFile* ptr;
	string fileName = "";
	string extension = "";
	istringstream iss(s);
	iss >> fileName;
	ptr = aff_ptr->createFile(fileName);
	if (ptr != nullptr) {
		if (iss >> extension) {
			if (extension == "-p") {
				string in_pswd;
				cout << "What is the password you want to create?" << endl;
				getline(cin, in_pswd);
				PasswordProxy* pswd = new PasswordProxy(ptr, in_pswd);
				int result = afs_ptr->addFile(fileName, pswd);
				if (result != successful) {
					cout << "Unable to add file to system." << endl;
					delete(ptr);
				}
				return result;
			}
		}
		else {
			cout << "creating new file" << endl;
			int result = afs_ptr->addFile(fileName, ptr);
			if (result != successful) {
				delete(ptr);
			}
			return result;
		}
	}
	else {
		return cannotCreateFile;
	}
	return failedCommand;
}







	/*if (extension == "-p") {
		ptr = aff_ptr->createFile(fileName);
		cout << "What is the password you want to create?" << endl;
		string in_pswd;
		cin >> in_pswd;
		PasswordProxy pswd = PasswordProxy(ptr,in_pswd);	
		if (ptr != nullptr) {
			int result = afs_ptr->addFile(fileName, &pswd);
		
			if (result != successful) {
				delete(ptr);
			}
			return result;
		}
		else {
			return cannotCreateFile;
		}
	}
	else

	{
		ptr = aff_ptr->createFile(fileName);
		cout << "creating new file" << endl;
		if (ptr != nullptr) {
			int result = afs_ptr->addFile(fileName, ptr);
			if (result != successful) {
				delete(ptr);
			}
			return result;
		}
		else {
			return cannotCreateFile;
		}
	}
		
	
}*/
