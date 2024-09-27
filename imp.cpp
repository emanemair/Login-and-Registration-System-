#include<iostream>
#include<string>
#include<fstream>
#include"user.h"
#include"userManager.h"
#include<regex>



using namespace std; 


bool UserManager::isValidEmail(const string& email)const{

	// Define a regular expression for a typical email pattern
	const std::regex pattern(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");

	// Return whether the email matches the regex
	return std::regex_match(email, pattern);
}

bool UserManager::isValidUserName(const string& name)const {

	// Define a regex pattern for the username
	std::regex pattern("^[A-Za-z][A-Za-z0-9_]*$");

	// Check if the username matches the pattern
	return std::regex_match(username, pattern);
}

bool UserManager::isValidPassword(const pass&)const {

	// Regex pattern for a valid password: at least 8 characters, at least one letter, and at least one symbol
	const std::regex pattern(R"((?=.*[a-zA-Z])(?=.*[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]).{8,})");

	// Check if the password matches the regex pattern
	return std::regex_match(password, pattern);
}



/*
bool UserManager::changeEamil(const string& newEmail) {
	string currentEmail; 
	this->getEmail(currentEmail);
	if (newEmail == currentEmail) {
		cout<<""
	}
}*/

UserManager::UserManager(string name, string email, string userName, string pass)
{
	this->users.push_back(User(name, email, userName, pass));
}

void User::setUser(string name, string email, string userName, string pass) {
	this->setName(name);
	this->setEmail(email);
	this->setUserName(userName);
	this->setPassword(pass);

}

User::User(string name, string email,string userName, string pass) {

	this->setUser(name, email, userName, pass); 
}

void UserManager::print()const {
	cout << "User Account Data:\n"; 
	User::print(); 
}



void User::setName(const string& name) {
	this->name = name;
}



void User::setUserName(const string& userName) {

	this->userName(userName); 
}

void User::setEmail(const string &email) {
	this->email = email; 
}

void User::setPassword(const string &pass) {

	this->password = pass; 
}

string User::getName()const {

	return this->name; 
}

string User::getUserName()const {

	return this->userName; 
}

string User::getEmail() const{

	return this->email; 
}

string  User::getPassword() const{

	return this->password; 
}

void User::print()const {
	cout << "name: " << this->name << "\nemail: " << this->email << "\nuser-name: " << this->userName << "\n"; 
}

bool UserManager::isUserExistByEmail(const string& email)const {
	bool isFound = false; 
	for (itr; itr != this->users.end(); itr++) {
		if (*itr->getEmail() == email) {
			return true; 
		} 
	}
	return false; 

}

User* UserManager::findUser(const string& email) const {
	
	for (itr ; itr != this->users.end(); ++itr) {
		
		if (*itr->getEmail() == email) {
			return *itr;  
		}
	}
	return nullptr;
}

bool UserManager::isUserExistByUserName(const string& uName) const {
	bool isFound = false;
	for (itr; itr != this->users.end(); itr++) {
		if (*itr->getUserName() == uName) {
			return  true; 
		}
	}
	return false; 
}


vector<User>* UserManager::getUsers()const {

	return &this->users;
}


void UserManager::Userregistration() {

	string email; 
	string uName; 
	string name;  
	string password;
	User user; 
	cout << "Enter your name:\n"; 
	cin >> name; 


	do {
		cout << "Enter your email:\n";
		cin >> email;
		email = static_cast<string>(email);
		if (!isValidEmail(email) || this->isUserExistByEmail(email)) {
			cout << "Invalid email" << endl;
		}
	} while (!isValidEmail(email)||this->isUserExistByEmail(email));

	cout << "Valid email: " << email << endl;




	do {
		cout << "Create username:\n";
		cin >> uName;
		name = static_cast<string>(uName);

		if (!isValidUsername(uName)||this->isUserExistByUserName(uName)) {
			cout << "Invalid user-name" << endl;
		}
	} while (!isValidUsername(uName)|| this->isUserExistByUserName(uName));

	cout << "Valid username: " << uName << endl;



	do {
		cout << "Create Password:\n";
		cin >> password;
		name = static_cast<string>(password);

		if (!isValidPassword(password) {
			cout << "Invalid Password" << endl;
		}
	} while (!isValidPassword(password));

	this->users.push_back(User(name, email, uName, password));

}


void UserManager::userLogin() {
	string email;
	string password; 
	User user; 
	cout << "Enter your Email:\n";
	cin >> email; 
	if (this->isUserExistByEmail(email)) {
		user = this->findUser(email); 
		cout << "Enter your password:\n";
		cin >> password; 
		if (password == user.getPassword()) {
			cout << "login complete, congrats\nwelcome " << user.getName() << "\n"; 
		}
		else {
			cout << "user dose not exist\n"; 
		}

	}
}


bool UserManager::changePass(const string& pass) {

	User user; 
	string current_pass; 
	string current_email;
	string new_password;

	cout << "Enter your Email: \n"; 
	cin >> current_email; 
	while (!this->isUserExistByEmail(current_email) || current_email != "-1") {
		cout << "user dose not exist:(try again)\nenter your email:or -1 to exist ";
		cin >> current_email; 
	}
	if (current_email == -1) {
		return false; 
	}
	else {

		user = this->findUser(current_email);
		cout << "welcome " << user.getUserName() << "\n";
		cout << "enter your current password: " << endl;
		cin >> current_pass;
		while (current_pass != user.getPassword()|| current_pass != "-1") {
			cout << "password wrong,(try again)\n enter current passwrod: or -1 to exist" << endl;
			cin >> current_pass;
		}
		if (current_pass == -1) {
			return false; 
		}
		
		cout << "enter new password : " << endl;
		cin >> new_password;
		while (!this->isValidPassword(new_password) || new_password != "-1") {
			cout << "invalid password: (try again)\nenter new password: or -1 to exist ";
			cin >> new_password;
		}
		if (new_password == -1) {
			return false;
		}
		user.setPassword(new_password);
		return true;


	}





}