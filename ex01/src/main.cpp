#include <string>
#include <iostream>
#include "PhoneBook.h"

static void display_commands(void)
{
	std::cout << "type 'ADD' to add a contact\n"
		"type 'SEARCH' to search for a contact\n"
		"type 'EXIT' to exit the program\n";
}

static int prompt_command(PhoneBook& phonebook)
{
	std::string input;
	std::getline(std::cin, input);
	if (std::cin.fail()) {
		if (!std::cin.eof()) {
			std::cerr << "getline: cin error "
				<< std::cin.rdstate() << "\n";
		}
		return (1);
	}
	else if (input == "ADD") {
		phonebook.add_contact();
	}
	else if (input == "SEARCH") {
		phonebook.search_contact();
	}
	else if (input == "EXIT") {
		return (1);
	}
	else {
		std::cout << "Incorrect command\n";
		display_commands();
	}
	return (0);
}

int main(void)
{
	display_commands();
	PhoneBook phonebook;
	while (1) {
		if (prompt_command(phonebook))
			return (0);
	}
}
