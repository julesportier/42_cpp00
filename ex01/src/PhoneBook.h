#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
private:
	Contact contacts[8];
	int update_contact_index(int contact_index);
	std::string prompt_user(std::string prompt);
	std::string prompt_phone_number(std::string prompt);
	bool validate_phone_number(std::string input);
};

#endif
