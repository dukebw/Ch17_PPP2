// Program to test the sizeof() various primitive types

#include <iostream>
#include <cstdlib>
#include <vector>

struct Date {
	int y, m, d;
};

void sizes(char ch, int i, int* p)
{
	std::cout << "the size of char is " << sizeof(char) << ' ' 
		<< sizeof(ch) << '\n';
	std::cout << "the size of int is " << sizeof(int) << ' ' 
		<< sizeof(i) << '\n';
	std::cout << "the size of int* is " << sizeof(int*) << ' ' 
		<< sizeof(p) << '\n';
}

void sizes_bool(bool b, bool* p)
{
	std::cout << "the size of bool is " << sizeof(bool) << ' ' 
		<< sizeof(b) << '\n';
	std::cout << "the size of bool* is " << sizeof(bool*) << ' ' 
		<< sizeof(p) << '\n';
}

void sizes_double(double d, double* p)
{
	std::cout << "the size of double is " << sizeof(double) << ' ' 
		<< sizeof(d) << '\n';
	std::cout << "the size of double* is " << sizeof(double*) << ' ' 
		<< sizeof(p) << '\n';
}

void sizes_Date(Date d, Date* p)
{
	std::cout << "the size of Date is " << sizeof(Date) << ' ' 
		<< sizeof(d) << '\n';
	std::cout << "the size of Date* is " << sizeof(Date*) << ' ' 
		<< sizeof(p) << '\n';
}

int main(int argc, char* argv[])
try {
	char ch{'a'};
	int i{7};
	int* p{&i};
	bool b{true};
	bool* pb{&b};
	double d{3.14};
	double* pd{&d};
	Date da{2014, 12, 31};
	Date* pda{&da};

	sizes(ch, i, p);
	sizes_bool(b, pb);
	sizes_double(d, pd);
	sizes_Date(da, pda);

	std::vector<int> v(1000);	// vector with 1000 elements of type int
	std::cout << "the size of vector<int>(1000) is " << sizeof(v) << '\n';
	return EXIT_SUCCESS;
}
catch(std::exception& e) {
	std::cerr << e.what() << std::endl;
}
catch(...) {
	// ...
}
