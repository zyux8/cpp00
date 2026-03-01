#include "phonebook.hpp"

Contact::Contact() {
}

std::string Contact::get_name() {
	return this->name;
}

std::string Contact::get_surname() {
	return this->surname;
}

std::string Contact::get_nickname() {
	return this->nickname;
}

std::string Contact::get_number() {
	return this->number;
}

std::string Contact::get_secret() {
	return this->secret;
}

void Contact::set_name(std::string value) {
	this->name = value;
}

void Contact::set_surname(std::string value) {
	this->surname = value;
}

void Contact::set_nickname(std::string value) {
	this->nickname = value;
}

void Contact::set_number(std::string value) {
	this->number = value;
}

void Contact::set_secret(std::string value) {
	this->secret = value;
}
