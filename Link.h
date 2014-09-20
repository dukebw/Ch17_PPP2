// Header for Link class
#include <iostream>

enum class Mythology {
	Greek, Norse, Egyptian
};

struct God {
	std::string name, vehicle, weapon;
	Mythology mythol;
};

class Link {
public:
	// causing compile error? const God& can't convert to std::string?
	Link(const God& g, Link* p = nullptr, Link* s = nullptr)
		:prev{p}, succ{s} 
	{
		god_val = g;
	}

	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase();
	// causing error because value (god_val) is a God not a string now?
	Link* find(const std::string& s);
	const Link* find(const std::string& s) const; // find s in const list

	// places its new element in its correct lexicographical position
	// returns pointer to first element in the list
	Link* add_ordered(Link* n); // assumes already ordered

	const Link* advance(int n) const;

	Link* find_start();

	Link* next() const { return succ; }
	Link* previous() const { return prev; }

	God god_val;
private:
	Link* prev;
	Link* succ;
};

bool operator>(const Link& a, const Link& b);

void print_all(Link*);

// returns mythology name as string
std::string mythology_name(const Mythology& mythol);
