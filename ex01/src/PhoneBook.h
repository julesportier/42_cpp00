#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
private:
	Contact contacts[8];
	int stored_contacts;
	void display_contact(int index);
	void display_field(std::string field);
	void display_row(Contact contact, int id);
	void display_column(std::string field);
	bool validate_index(int index);
	int update_contact_index(int contact_index);
	std::string prompt_user(std::string prompt);
	std::string prompt_string(std::string input);
	bool validate_string(std::string input);
	std::string prompt_phone_number(std::string input);
	bool validate_phone_number(std::string input);
};

#endif
