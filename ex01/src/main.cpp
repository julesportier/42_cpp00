#include <string>
#include <iostream>
#include "PhoneBook.h"

static void display_commands(void)
{
	std::cout << "type 'ADD' to add a contact\n"
		"type 'SEARCH' to search for a contact\n"
		"type 'EXIT' to exit the program\n";
}

static bool prompt_command(PhoneBook& phonebook)
{
	std::string input;
	std::getline(std::cin, input);
	if (input == "ADD") {
		phonebook.add_contact();
	}
	else if (input == "SEARCH") {
		phonebook.search_contact();
	}
	else if (input == "EXIT") {
		return (false);
	}
	else {
		std::cout << "Incorrect command\n";
		display_commands();
	}
	return (true);
}

int main(void)
{
	display_commands();
	PhoneBook phonebook;
	while (1) {
		if (prompt_command(phonebook) == false)
			return (0);
	}
}
