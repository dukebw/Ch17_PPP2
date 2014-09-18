// copies a C-style string into memory it allocates on the free store
#include <iostream>

char* strdup(const char* str)
{
	int size{0};
	for (; str[size] != '\0'; ++size);
	char* c = new char[size];
	for (int i=0; i<size; ++i)
		c[i] = str[i];
	return c; 
}

int main()
{
	char str[] = "Derp";
	char* str2 = strdup(str);
	std::cout << str2 << std::endl;
}
