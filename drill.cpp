// Ch17 Drill
#include <iostream>
#include <vector>

void print_array10(std::ostream& os, int* a, int n)
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
	constexpr int max1{10}, max2{11}, max3{20}, start{100};
	int* a{new int[max1]};
	int* b{new int[max2]};
	int* c{new int[max3]};
	std::vector<int> va(max1), vb(max2), vc(max3);

	for (unsigned i=0; i<va.size(); ++i)
		va[i] = start + i;
	for (unsigned i=0; i<vb.size(); ++i)
		vb[i] = start + i;
	for (unsigned i=0; i<vc.size(); ++i)
		vc[i] = start + i;

	for (int i=0; i<max1; ++i)
		a[i] = start + i;
	for (int i=0; i<max2; ++i)
		b[i] = start + i;
	for (int i=0; i<max3; ++i)
		c[i] = start + i;
	print_array10(std::cout, a, max1);
	print_array10(std::cout, b, max2);
	print_array10(std::cout, c, max3);
	print_vector(std::cout, va);
	print_vector(std::cout, vb);
	print_vector(std::cout, vc);
	delete[] a;
	delete[] b;
	delete[] c;
	a = b = c = nullptr;
	return 0;
}
