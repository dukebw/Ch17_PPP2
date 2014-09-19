// reads characters from std::cin into a string allocates on the free store
// automatically.
// individual characters are read until a '!' is reached
#include <iostream>

int main()
{
	std::string str;

	char c;
	while(std::cin.get(c)) {
		if (c == '!')
			break;
		else
			str.push_back(c);
	}
	std::cout << str << std::endl;
}
