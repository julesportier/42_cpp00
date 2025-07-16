#include <iostream>
#include "PhoneBook.h"

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

void PhoneBook::add_contact() {
	static int contact_index = 0;
	contacts[contact_index].set_first_name(prompt_user("FIRST NAME: "));
	contacts[contact_index].set_last_name(prompt_user("LAST NAME: "));
	contacts[contact_index].set_nickname(prompt_user("NICKNAME: "));
	contacts[contact_index].set_phone_number(
			prompt_phone_number("PHONE NUMBER: "));
	contacts[contact_index].set_darkest_secret(
			prompt_user("DARKEST SECRET: "));
	contact_index = update_contact_index(contact_index);
};


// PhoneBook::print_book() {

// Private methods
std::string PhoneBook::prompt_user(std::string prompt) {
	std::cout << prompt << '\n';
	std::string input;
	std::getline(std::cin, input);
	return (input);
};

std::string PhoneBook::prompt_phone_number(std::string prompt) {
	std::string phone_number;
	do {
		phone_number = prompt_user(prompt);
	}
	while (validate_phone_number(phone_number) == false);
	return (phone_number);
}

bool validate_phone_number(std::string input) {
	std::string::size_type i = 0;
	std::string::size_type input_size = input.size();
	while (i < 10 && i < input_size) {
		if (!isdigit(input[i]))
		{
			std::cerr << "Phone number must contain only digits\n";
			return (false);
		}
		++i;
	}
	if (i == 10)
		return (true);
	else
	{
		std::cerr << "Phone number must contain ten digits\n";
		return (false);
	}
}

int update_contact_index(int contact_index) {
	if (contact_index == 7)
		contact_index = 0;
	else
		++contact_index;
	return (contact_index);
}
