#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else {
		for (int x = 1; av[x]; x++) {
			for (int y = 0; av[x][y]; y++) {
				if (av[x][y] >= 97 && av[x][y] <= 122)
					av[x][y] -= 32;
			}
			std::cout << av[x];
		}
	}
	return 0;
}
