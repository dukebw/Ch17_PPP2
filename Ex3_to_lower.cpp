// replaces all uppercase characters in the C-style string s with their
// lowercase equivalents
#include<iostream>

void to_lower(char* s)
{
	int i{0};
	while(s[i] != '\0') {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
		++i;
	}
}

int main()
{
	char s[] = "SILLY HaHa4";
	to_lower(s);
	std::cout << s << std::endl;
	return 0;
}
