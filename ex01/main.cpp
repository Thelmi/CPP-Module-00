#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	std::string command;
	PhoneBook phoneBook;

	while (1)
	{
		std:: cout << "Choose a command ADD, SEARCH, and EXIT" << std:: endl;
		if (!std:: getline(std:: cin, command))
		{
			std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
			return (1);
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.displaySpecificContact();
		}
		else if (command == "EXIT")
			break ;
		else
			std:: cout << "Error! invalid command: choose a command ADD, SEARCH, and EXIT" << std:: endl;
	} 
	return (0);
}