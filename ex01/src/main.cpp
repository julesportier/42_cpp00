#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"

int main(void)
{
	Contact	test;
	
	test.set_phone_number("0642424242");
	std::cout << test.get_phone_number() << '\n';
	return (0);
}
