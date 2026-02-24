#include "phonebook.hpp"

Phonebook::Phonebook() {
	Phonebook::contact_count = 0;
}

bool valid_number(std::string input) {
	if (input.empty())
		return false;
	for (int x = 0; input[x]; x++) {
		if ((input[x] >= '0' && input[x] <= '9') || input[x] == '+' || input[x] == '-' || input[x] == ' ')
			continue;
		else 
			return false;
	}
	return true;
}

void Phonebook::add_contact(Contact new_contact) {
	if (contact_count > 7) {
		contact_count = 0;
	}
	contact[contact_count] = new_contact;
	contact_count++;
}

bool get_string(std::string msg, std::string &output) {
	while (1) {
		std::cout << msg;
		if (!std::getline(std::cin, output)) {
			std::cin.clear();
			return false;
		}
		if (output.empty())
			continue;
		else
			return true;
	}
}

bool read_contact(Phonebook &pb) {
	std::string input;
	Contact contact;

	if (!get_string("Enter the Name of the contact: ", input))
		return false;
	contact.set_name(input);
	if (!get_string("Enter the Last Name of the contact: ", input))
		return false;
	contact.set_surname(input);
	if (!get_string("Enter the Nickname of the contact: ", input))
		return false;
	contact.set_nickname(input);
	while(!valid_number(input)) {
		if (!get_string("Enter the Number of the contact: ", input))
			return false;
	}
	contact.set_number(input);
	if (!get_string("Enter the Hilarious Secret of the contact >:]\n", input))
		return false;
	contact.set_secret(input);
	std::cout << "Contact saved" << std::endl;
	pb.add_contact(contact);
	return true;
}

void print_line() {
	std::cout << "+";
	for (int x = 0; x < 43; x++)
		std::cout << "-";
	std::cout << "+" << std::endl;
}

void print10(std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << "." << "|";
	else {
		std::cout << str;
		int x = str.length();
		while (x++ < 10)
			std::cout << " ";
		std::cout << "|";
	}
}

void Phonebook::display_phonebook() {
	print_line();
	std::cout << "| Index    | Name     | Surname  | Nickname |" << std::endl;
	for (int x = 0; x < 8; x++) {
			std::cout << "| " << x << "        |";
			print10(this->contact[x].get_name());
			print10(this->contact[x].get_surname());
			print10(this->contact[x].get_nickname());
			std::cout << std::endl;
	}
	print_line();
}

bool valid_contact(std::string str) {
    int value;
    if (str.empty()) {
        return false;
    }
    for (std::size_t i = 0; i < str.size(); i++) {
        if ((str[i] >= '0' && str[i] <= '9')) {
            continue;
        } else {
            return false;
        }
    }
    value = atoi(str.c_str());
    if (value >= 0 && value <= 7) {
        return true;
    }
    return false;
}

void Phonebook::display_contact(int index) {
	std::cout << "Contact information" << std::endl;
	std::cout << "Name: " << this->contact[index].get_name() << std::endl;
	std::cout << "Surname: " << this->contact[index].get_surname() << std::endl;
	std::cout << "Nickname: " << this->contact[index].get_nickname() << std::endl;
	std::cout << "Number: " << this->contact[index].get_number() << std::endl;
	std::cout << "Hilarious Secret: " << this->contact[index].get_secret() << std::endl;
}

void search_contact(Phonebook pb) {
	pb.display_phonebook();
	std::string input;
	std::cout << "Enter the index of a contact: ";
	while (std::getline(std::cin, input) && !valid_contact(input))
		std::cout << "Please enter a valid index number of a contact: ";
	pb.display_contact(atoi(input.c_str()));
}

void testing(Phonebook &pb) {
	for (int x = 0; x < 8; x++) {
		Contact con;
		con.set_name("test");
		con.set_surname("surtest");
		con.set_nickname("nicknametest");
		con.set_number("test69");
		con.set_secret("secrettest");
		pb.add_contact(con);
	}
}

int main() {
	std::string input;
	Phonebook pb;

	while (1) {
	std::cout << "Hello sir: ";
	if (!std::getline(std::cin, input))
		return (1);
	if (input == "ADD") {
		if (!read_contact(pb))
			return 1;
	}
	else if (input == "SEARCH")
		search_contact(pb);
	else if (input == "test")
		testing(pb);
	else if (input == "EXIT")
		break;
	else
		continue;
	}
	return 0;
}
