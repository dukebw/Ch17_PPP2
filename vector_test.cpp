// Program for testing gradually refined versions of vector
#include <iostream>

// a very simplified vector of doubles
class vector {
	int sz; // the size
	double* elem; // a pointer to the elements
public:
	vector(int s) :sz{s}, elem{new double[s]} {}
	~vector() { delete[] elem; }

	int size() const { return sz; }
	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }
};

int main()
{
	vector* p = new vector(4);
	int x{p->size()};
	double d{p->get(3)};
	std:: cout << "x: " << x << '\t' << "d: " << d << std::endl;
	return 0;
}
