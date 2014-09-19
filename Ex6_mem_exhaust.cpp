// infinite loop that allocates and never deallocates to find out how much memory
// can be allocated before failing, and what happens when you run out of memory
#include <iostream>
#include <vector>
#include <exception>

int main()
try {
	std::vector<char*> vc;
	for(int i=0;;++i) {
		char* p = new char[10000];
		vc.push_back(p); // keep the memory referenced
		p[0] = 'x'; // use the memory
		std::cout << i << std::endl;
	}
}
catch (std::bad_alloc) {
	std::cerr << "Memory overflow\n"; 
}
