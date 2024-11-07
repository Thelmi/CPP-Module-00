#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact contacts[8];
		int contactCount;
		std::string truncateWithDot(const std::string str, std::size_t width);
	public:
		PhoneBook();
		void addContact();
		void displayContacts();
		void displaySpecificContact();
} ;