#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <stdlib.h>
# include "contact.hpp"

class Phonebook {
	private:
		Contact contact[8];
		int contact_count;
	public:
		Phonebook();
		void add_contact(Contact new_contact);
		void display_phonebook();
		void display_contact(int index);
};

#endif
