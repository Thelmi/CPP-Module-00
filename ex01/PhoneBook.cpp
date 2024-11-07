#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

void PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;

	std::cout << "Enter First Name: ";
	if (!std:: getline(std:: cin, first))
	{
		std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
		return ;
	}

	std::cout << "Enter Last Name: ";
	if (!std:: getline(std:: cin, last))
	{
		std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
		return ;
	}

	std::cout << "Enter Nickname: ";
	if (!std:: getline(std:: cin, nick))
	{
		std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
		return ;
	}

	std::cout << "Enter Phone Number: ";
	if (!std:: getline(std:: cin, phone))
	{
		std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
		return ;
	}

	std::cout << "Enter Darkest Secret: ";
	if (!std:: getline(std:: cin, secret))
	{
		std::cerr << "Input error! (maybe EOF or invalid input encountered)" << std:: endl;
		return ;
	}

	Contact newContact;
	if (newContact.setContact(first, last, nick, phone, secret))
	{
		if (contactCount < 8) 
			contacts[contactCount++] = newContact;
		else 
		{
			int i = 1;
			while (i < 8)
			{
				contacts[i - 1] = contacts[i];
				i++;
			}
			contacts[7] = newContact;
		}
	}
}

std::string PhoneBook::truncateWithDot(const std::string str, std::size_t width)
{
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    }
    return str;
}

void PhoneBook::displayContacts()
{
    std::cout << std::setw(10) << std::right << "Index"
              << " | " << std::setw(10) << std::right << "First Name"
              << " | " << std::setw(10) << std::right << "Last Name"
              << " | " << std::setw(10) << std::right << "Nickname" << std::endl;

    std::cout << "----------------------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; i++)
	{
        std::cout << std::setw(10) << std::right << i
                  << " | " << std::setw(10) << std::right << truncateWithDot(contacts[i].getFirstName(), 10)
                  << " | " << std::setw(10) << std::right << truncateWithDot(contacts[i].getLastName(), 10)
                  << " | " << std::setw(10) << std::right << truncateWithDot(contacts[i].getNickName(), 10)
                  << std::endl;
    }
}

void PhoneBook::displaySpecificContact()
{
	int index;
	std::string::size_type i = 0;
	std::string input;

	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);

	while (i < input.length())
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "ERORR! index shoud be numerical and not a negative number" << std:: endl;
			return ;
		}
		i++;
	}
	index = std::stoi(input);
	if (index >= contactCount) 
	{
        std::cout << "Error: Invalid index!" << std::endl;
        return;
    }
	std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}
