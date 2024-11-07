#include "Contact.hpp"

bool Contact::setContact(std::string first, std::string last, std::string nick, std::string phone, std::string secret)
{
	std::string::size_type i = 0;

	if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty()) 
	{
		std::cout << "Error: All fields must be filled.\n";
		return (false);
	}
	while (i < phone.length())
	{
		if (!std::isdigit(phone[i]))
		{
			std::cout << "ERORR! Phone should be numerical" << std:: endl;
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < first.length())
	{
		if (!std::isalpha(first[i]))
		{
			std::cout << "ERORR! Only alphabets in firstname" << std:: endl;
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < last.length())
	{
		if (!std::isalpha(last[i]))
		{
			std::cout << "ERORR! Only alphabets in lastname" << std:: endl;
			return (false);
		}
		i++;
	}
	firstName = first;
	lastName = last;
	nickName = nick;
	phoneNumber = phone;
	darkestSecret = secret;
	return (true);
}

std::string Contact::getFirstName()
{
	return(firstName);
}
std::string Contact::getLastName()
{
	return(lastName);
}
std::string Contact::getNickName()
{
	return(nickName);
}
std::string Contact::getPhoneNumber()
{
	return(phoneNumber);
}
std::string Contact::getDarkestSecret()
{
	return(darkestSecret);
}
