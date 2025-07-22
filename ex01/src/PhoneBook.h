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
	std::string prompt_string(std::string input);
	bool validate_string(std::string input);
	std::string prompt_phone_number(std::string input);
	bool validate_phone_number(std::string input);
};

#endif
