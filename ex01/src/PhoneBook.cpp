#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "PhoneBook.h"

PhoneBook::PhoneBook() : stored_contacts(0) {};

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	static int contact_index = 0;
	contacts[contact_index].set_first_name(
		prompt_string("FIRST NAME: ")
	);
	contacts[contact_index].set_last_name(
		prompt_string("LAST NAME: ")
	);
	contacts[contact_index].set_nickname(
		prompt_string("NICKNAME: ")
	);
	contacts[contact_index].set_phone_number(
		prompt_phone_number("PHONE NUMBER: ")
	);
	contacts[contact_index].set_darkest_secret(
		prompt_string("DARKEST SECRET: ")
	);
	if (std::cin.fail()) {
		return;
	}
	contact_index = update_contact_index(contact_index);
	if (this->stored_contacts < 8)
		++this->stored_contacts;
	std::cout << "Contact added\n";
}

void PhoneBook::search_contact() const
{
	if (this->stored_contacts == 0) {
		std::cout << "No saved contact\n";
		return;
	}
	for (int i = 0; i < this->stored_contacts; ++i) {
		PhoneBook::display_row(PhoneBook::contacts[i], i);
	}
	std::string input;
	do {
		std::cout << "Prompt the index of the contact "
			"you want do display: ";
		std::getline(std::cin, input);
		if (std::cin.fail()) {
			if (!std::cin.eof()) {
				std::cerr << "getline: cin error "
					<< std::cin.rdstate() << "\n";
			}
			return;
		}
	} while (PhoneBook::validate_index(input) == false);
	PhoneBook::display_contact(atoi(input.c_str()));
}

/******************
* PRIVATE METHODS *
* ****************/
void PhoneBook::display_contact(int index) const
{
	std::cout << "First name: ";
	PhoneBook::display_field(
		PhoneBook::contacts[index].Contact::get_first_name()
	);
	std::cout << "Last name: ";
	PhoneBook::display_field(
		PhoneBook::contacts[index].Contact::get_last_name()
	);
	std::cout << "Nickname: ";
	PhoneBook::display_field(
		PhoneBook::contacts[index].Contact::get_nickname()
	);
	std::cout << "Phone number: ";
	PhoneBook::display_field(
		PhoneBook::contacts[index].Contact::get_phone_number()
	);
	std::cout << "Darkest secret: ";
	PhoneBook::display_field(
		PhoneBook::contacts[index].Contact::get_darkest_secret()
	);
}

void PhoneBook::display_field(std::string field) const
{
	std::cout << field << '\n';
}

bool PhoneBook::validate_index(std::string input) const
{
	if (input.size() != 1 || input[0] < '0' || input[0] > '8') {
		std::cout << "Index out of range, "
			"look in leftmost column\n";
		return (false);
	}
	int index = atoi(input.c_str());
	if (index + 1 > this->stored_contacts) {
		std::cout << "Index is too big, "
			"look in leftmost column\n";
		return (false);
	}
	return (true);
}

void PhoneBook::display_row(Contact contact, int id) const
{
	char c[2];
	sprintf(c, "%d", id);
	std::string str = c;
	display_column(str);
	display_column(contact.Contact::get_first_name());
	display_column(contact.Contact::get_last_name());
	display_column(contact.Contact::get_nickname());
	std::cout << '\n';
}

void PhoneBook::display_column(std::string field) const
{
	std::cout << std::setw(10) << std::setfill(' ');
	std::cout << std::setiosflags(std::ios::right);
	if (field.size() > 10) {
		field[9] = '.';
		field.resize(10);
	}
	std::cout << field << '|';
	std::cout << std::resetiosflags(std::ios::right);
}

int PhoneBook::update_contact_index(int contact_index)
{
	if (contact_index == 7)
		contact_index = 0;
	else
		++contact_index;
	return (contact_index);
}

std::string PhoneBook::prompt_user(std::string prompt) const
{
	if (std::cin.fail()) {
		return ("");
	}
	std::cout << prompt;
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.fail()) {
		if (!std::cin.eof()) {
			std::cerr << "getline: cin error "
				<< std::cin.rdstate() << "\n";
		}
		return ("");
	}
	return (input);
}

std::string PhoneBook::prompt_string(std::string prompt) const
{
	std::string input;
	do {
		input = prompt_user(prompt);
	} while (!std::cin.fail()
			&& PhoneBook::validate_string(input) == false);
	return (input);
}

bool PhoneBook::validate_string(std::string input) const
{
	if (input.size() < 1) {
		std::cerr << "You must type something!\n";
		return (false);
	}
	return (true);
}

std::string PhoneBook::prompt_phone_number(std::string prompt) const
{
	std::string input;
	do {
		input = prompt_user(prompt);
	} while (!std::cin.fail()
			&& PhoneBook::validate_phone_number(input) == false);
	return (input);
}

bool PhoneBook::validate_phone_number(std::string input) const
{
	std::string::size_type input_size = input.size();
	if (input_size != 10) {
		std::cerr << "Phone number must contain ten digits\n";
		return (false);
	}
	for (std::string::size_type i = 0; i < input_size; ++i) {
		if (!isdigit(input[i])) {
			std::cerr << "Phone number must contain only digits\n";
			return (false);
		}
	}
	return (true);
}
