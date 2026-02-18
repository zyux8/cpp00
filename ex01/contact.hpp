#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		std::string get_name();
		std::string get_surname();
		std::string get_nickname();
		std::string get_number();
		std::string get_secret();
		void set_name(std::string value);
		void set_surname(std::string value);
		void set_nickname(std::string value);
		void set_number(std::string value);
		void set_secret(std::string value);
};

#endif