#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.h"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact() const;
private:
	Contact contacts[8];
	int stored_contacts;
	void display_contact(int index) const;
	void display_field(std::string field) const;
	void display_row(Contact contact, int id) const;
	void display_column(std::string field) const;
	bool validate_index(std::string input) const;
	int update_contact_index(int contact_index);
	std::string prompt_user(std::string prompt) const;
	std::string prompt_string(std::string input) const;
	bool validate_string(std::string input) const;
	std::string prompt_phone_number(std::string input) const;
	bool validate_phone_number(std::string input) const;
};

#endif
