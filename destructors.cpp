// Program for testing order of destructor and constructor calls
#include <iostream>

class B1 {
protected:
	B1() { std::cout << "B1 constructor\n"; } 
public:
	virtual ~B1() { std::cout << "B1 destructor\n"; } 
};

struct C1 : B1 {
	C1() { std::cout << "C1 constructor\n"; } 	
	virtual ~C1() { std::cout << "C1 destructor\n"; } 	
};

class MC2 {
public:
	MC2() { std::cout << "MC2 constructor\n"; }
	~MC2() { std::cout << "MC2 destructor\n"; }
};

struct C2 : B1 {
	C2() { std::cout << "C2 constructor\n"; } 	
	~C2() { std::cout << "C2 destructor\n"; } 	
private:
	MC2 mC2;
};

struct C3 : B1 {
	C3() { std::cout << "C3 constructor\n"; } 	
	~C3() { std::cout << "C3 destructor\n"; } 	
};

struct D1 : C1 {
	D1() { std::cout << "D1 constructor\n"; } 	
	~D1() { std::cout << "D1 destructor\n"; } 	
private:
	C2 c2;
	C3 c3;
};

B1* fct()
{
	B1* p{new D1};
	return p;
}

void f()
{
	B1* b1{fct()};
	delete b1;
}

int main()
{
	f();
	return 0;
}
