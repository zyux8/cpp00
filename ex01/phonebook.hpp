#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include "contact.hpp"

class Phonebook {
	private:
		Contact contact[7];
	public:
		void add_contact(Contact new_contact);
		void display_phonebook();
		void display_contact();
};

#endif
