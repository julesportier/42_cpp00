#include "Contact.h"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void Contact::set_nickname(std::string str)
{
	this->nickname = str;
}

void Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string Contact::get_first_name() const
{
	return (this->first_name);
}

std::string Contact::get_last_name() const
{
	return (this->last_name);
}

std::string Contact::get_nickname() const
{
	return (this->nickname);
}

std::string Contact::get_phone_number() const
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret() const
{
	return (this->darkest_secret);
}
