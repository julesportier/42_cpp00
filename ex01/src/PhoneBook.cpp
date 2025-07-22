#include <iostream>
#include "PhoneBook.h"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact()
{
	static int contact_index = 0;
	contacts[contact_index].set_first_name(
			prompt_string("FIRST NAME: "));
	contacts[contact_index].set_last_name(
			prompt_string("LAST NAME: "));
	contacts[contact_index].set_nickname(
			prompt_string("NICKNAME: "));
	contacts[contact_index].set_phone_number(
			prompt_phone_number("PHONE NUMBER: "));
	contacts[contact_index].set_darkest_secret(
			prompt_string("DARKEST SECRET: "));
	contact_index = update_contact_index(contact_index);
}

/******************
* PRIVATE METHODS *
* ****************/
int PhoneBook::update_contact_index(int contact_index)
{
	if (contact_index == 7)
		contact_index = 0;
	else
		++contact_index;
	return (contact_index);
}

std::string PhoneBook::prompt_user(std::string prompt)
{
	std::cout << prompt << '\n';
	std::string input;
	std::getline(std::cin, input);
	return (input);
}

std::string PhoneBook::prompt_string(std::string prompt)
{
	std::string input;
	do {
		input = prompt_user(prompt);
	} while (PhoneBook::validate_string(input) == false);
	return (input);
}

bool PhoneBook::validate_string(std::string input)
{
	if (input.size() < 1) {
		std::cerr << "You must type something!\n";
		return (false);
	}
	return (true);
}

std::string PhoneBook::prompt_phone_number(std::string prompt)
{
	std::string input;
	do {
		input = prompt_user(prompt);
	} while (PhoneBook::validate_phone_number(input) == false);
	return (input);
}

bool PhoneBook::validate_phone_number(std::string input)
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

// PhoneBook::print_book() {
