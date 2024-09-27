#include<string>



class User {
	string name;
	string userName;
	string email;
	string password;
public:
	User(string = "", string = "", string = "", string = "");
	void setUser(string, string, string, string); 
	void setName(const string&);
	void setUserName(const string&);
	void setEmail(const string&);
	void setPassword(const string&);
	void print()const;
	string getName() const;
	string getUserName()const;
	string getEmail() const;
	string getPassword()const;
	
	
	

};