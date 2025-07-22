#include <iostream>
#include "Contact.h"
#include "PhoneBook.h"

int main(void)
{
	Contact	test;
	PhoneBook pb;
	
	test.set_phone_number("0642424242");
	std::cout << test.get_phone_number() << '\n';
	pb.add_contact();
	return (0);
}
