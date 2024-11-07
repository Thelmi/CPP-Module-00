#ifndef ex01_h
# define ex01_h

#include <iostream>
#include <string>
#include <iomanip>

class	Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		bool setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret);
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
} ;

#endif