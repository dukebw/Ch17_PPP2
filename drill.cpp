// Ch17 Drill
#include <iostream>
#include <vector>

void print_array(std::ostream& os, int* a, int n)
{
	for (int i=0; i<n; ++i)
		os << a[i] << std::endl;
}

void print_vector(std::ostream& os, const std::vector<int>& v)
{
	for (int i : v)
		os << i << std::endl;
}

int main()
{
	int* p1 = new int[10];
	for (int i=0; i<10; ++i)
		p1[i] = (i == 0) ? 1 : 2*p1[i-1];

	int* p2 = new int[10];
	for (int i=0; i<10; ++i) {
		p2[i] = p1[i];
		std::cout << p2[i] << std::endl;
	}

	std::vector<int> v1(10);
	for (unsigned i=0; i<v1.size(); ++i)
		v1[i] = (i == 0) ? 1 : 2*v1[i-1];

	std::vector<int> v2(10);
	for (unsigned i=0; i<v2.size(); ++i) {
		v2[i] = v1[i];
		std::cout << v2[i] << std::endl;
	}
	return 0;
}
