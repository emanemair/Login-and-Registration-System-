#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include <typeinfo> 
#include <type_traits>  // For std::is_same

using namespace std;
ofstream create_user_data_file();
void user_registration();
bool isValidEmail(const string&);

/*bool isValidEmailType(const T&);*/


int main() {

	user_registration();

	return 0;
}


bool isValidEmail(const string& email) {
	// Define a regular expression for a typical email pattern
	const std::regex pattern(R"((\w+)(\.|\_)?(\w*)@(\w+)(\.(\w+))+)");

	// Return whether the email matches the regex
	return std::regex_match(email, pattern);
}

bool isValidUsername(const std::string& username) {
	// Define a regex pattern for the username
	std::regex pattern("^[A-Za-z][A-Za-z0-9_]*$");

	// Check if the username matches the pattern
	return std::regex_match(username, pattern);
}
/*
template<typename T>
bool isValidEmailType(const T&) {
	if (std::is_same<decltype(T), string>::value) {
		return true;
	}
	return false;
}*/


void   user_registration() {

	string email;
	string name;
	string password;

	do {
		cout << "Enter your email:\n";
		cin >> email;
		email = static_cast<string>(email);
		if (!isValidEmail(email)) {
			cout << "Invalid email" << endl;
		}
	} while (!isValidEmail(email));

	cout << "Valid email: " << email << endl;
	
	ofstream file = create_user_data_file(); 
	file << email << ","; 
	
	
	do {
		cout << "Enter username:\n";
		cin >> name;
		name = static_cast<string>(name);

		if (!isValidUsername(name)) {
			cout << "Invalid name" << endl;
		}
	} while (!isValidUsername(name));

	cout << "Valid username: " << name << endl;
	file << name << ",";
	file << "\n"; 
	file.close();


}


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