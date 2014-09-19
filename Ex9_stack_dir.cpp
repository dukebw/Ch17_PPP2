// to determine which way the stack grows: up (toward higher addresses) or down
// (toward lower addresses). Likewise for the free store (before I use delete)
#include <iostream>

int main()
{
	int x{2};
	int y{3};
	int z{5};

	std::cout << &x << '\t' << &y << '\t' << &z << std::endl;

	int* i = new int{7};
	int* j = new int{11};
	int* k = new int{13};

	std::cout << i << '\t' << j << '\t' << k << std::endl;
}
