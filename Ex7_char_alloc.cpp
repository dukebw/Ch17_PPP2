// reads characters from std::cin into an array that is allocated on the free store.
// individual characters are read until a '!' is reached
#include <iostream>

int main()
{
	constexpr int MAXLINE{10};
	char* pc = new char[MAXLINE];

	int i=0;
	char c;
	while(std::cin.get(c)) {
		if (i >= MAXLINE) break;
		if (c == '!') {
			pc[i] = '\0';
			break;
		}
		else
			pc[i++] = c;
	}
	std::cout << pc << std::endl;
}
