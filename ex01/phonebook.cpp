#include "phonebook.hpp"



bool valid_number(std::string input) {
	for (int x = 0; input[x]; x++) {
		if ((input[x] >= '0' && input[x] <= '9') || input[x] == '+' || input[x] == '-')
			continue;
		else 
			return false;
	}
	return true;
}

void read_contact(Phonebook &pb) {
	std::string input;
	Contact contact;

	std::cout << "Enter the Name of the contact" << std::endl;
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter the Name of the contact" << std::endl;
	contact.set_name(input);
	std::cout << "Enter the Last Name of the contact" << std::endl;
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter the Last Name of the contact" << std::endl;
	contact.set_surname(input);
	std::cout << "Enter the Nickname of the contact" << std::endl;
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter the Nickname of the contact" << std::endl;
	contact.set_nickname(input);
	std::cout << "Enter the Number of the contact" << std::endl;
	while (std::getline(std::cin, input) && valid_number(input))
		std::cout << "Enter the Number of the contact" << std::endl;
	contact.set_number(input);
	std::cout << "Enter the Darkest Secret of the contact >:]" << std::endl;
	while (std::getline(std::cin, input) && input.empty())
		std::cout << "Enter the Darkest Secret of the contact >:]" << std::endl;
	contact.set_secret(input);
	pb.add_contact(contact);
}

void search_contact(Phonebook pb) {

}

int main() {
	std::string input;
	Phonebook pb;

	while (1) {
	std::cout << "Waiting for input: ";
	std::getline(std::cin, input);
	std::cout << "input: " << input << "\n";
	if (input == "ADD")
		read_contact(pb);
	if (input == "SEARCH")
		search_contact(pb);
	if (input == "EXIT")
		break;
	}
	return 0;
}
