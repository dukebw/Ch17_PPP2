// Header for Link class
#include <iostream>

class Link {
public:
	std::string value;

	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		:value{v}, prev{p}, succ{s} {}

	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase();
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const; // find s in const list

	const Link* advance(int n) const;

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};

void print_all(Link*);
