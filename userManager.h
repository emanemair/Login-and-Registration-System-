#include"user.h"
#include<string>
#include<vector>

using namespace std; 

class UserManager {

	vector<User> users; 
	vector<User>::iterator itr = users.begin(); 

publci: 
	UserManager(string, string, string, string); 

	void print()const; 
	bool isValidEmail(const string&)const; 
	bool isValidUserName(const string&)const; 
	bool isValidPassword(const pass&)const;
	void Userregistration(); 
	void userLogin();
	User*  findUser(const string&)const; 
	bool isUserExistByEmail(const string&)const; 
	bool isUserExistByUserName(const string&)const; 
	void writeToFile(std::ofstream& ofs) const;
	users getUsers()const; 
	bool changePass(const string& newPass); 
	

};



ofstream  create_user_data_file() {

	ofstream file;

	// Opening file "Gfg.txt" in write mode.
	file.open("user_data.txt");

	// Check if the file was successfully created.
	if (!file.is_open())
	{
		cout << "Error in creating file!" << endl;

		// Return a non-zero value to indicate an error.
		return file;
	}
	cout << "File created successfully." << endl;

	// Close the file to free up resources.

	return file;
}