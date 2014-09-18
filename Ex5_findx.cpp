// finds the first occurence of the C-style string x in s
#include <iostream>

const char* findx(const char* s, const char* x)
{
	int size_x{0};
	int size_s{0};
	for (; x[size_x] != '\0'; ++size_x);
	for (; s[size_s] != '\0'; ++size_s);

	bool match{true};
	for (int i=0; s[i] != '\0' && i+size_x <= size_s; ++i) {
		for (int j=0; j<size_x && match; ++j) {
			if (s[i+j] != x[j]) match = false;
		}	
		if (match) return &s[i];
		match = true;
	}
	return nullptr;
}

int main()
{
	char str[] = "Derpdiderp";
	char str2[] = "did";
	const char* c = findx(str, str2);
	std::string str3;
	for (int i=0; c[i] != '\0'; ++i)
		str3 += c[i];
	std::cout << str3 << std::endl;
}
