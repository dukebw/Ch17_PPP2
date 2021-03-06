#include <string>
#include <iostream>
#include "Link.h"

bool operator>(const Link& a, const Link& b)
{
	return (a.god_val.name > b.god_val.name) ? true : false;
}

Link* Link::insert(Link* n) // insert n before this Link
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->succ = this;	// this comes after n
	if (prev) prev->succ = n;
	n->prev = prev;
	prev = n;
	return n;
}

Link* Link::add(Link* n) // insert n after this Link; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n->prev = this; // this comes before n
	if (succ) succ->prev = n;
	n->succ = succ;
	succ = n;
	return n;
}

Link* Link::erase() // remove *p from list; return p's successor
{
	if (this == nullptr) return nullptr;
	if (succ) succ->prev = prev;
	if (prev) prev->succ = succ;
	return succ;
}

Link* Link::find(const std::string& s)
{
	Link* p{this};
	while (p) {
		if (p->god_val.name == s) return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const std::string& s) const
{
	const Link* p{this};
	while (p) {
		if (p->god_val.name == s) return p;
		p = p->succ;
	}
	return nullptr;
}

// bug with add_ordered
Link* Link::add_ordered(Link* n) // assumes already ordered
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	if (*n > *this)
		(succ) ? succ->add_ordered(n) : add(n);
	else insert(n);
	return this->find_start();
}

// move n positions in list; return nullptr for "not found"
const Link* Link::advance(int n) const
{
	const Link* p{this};
	if (p == nullptr) return nullptr;
	if (n > 0) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr) return nullptr;
			p = p->prev;
		}
	}
	return p;
}

Link* Link::find_start()
{
	if (this == nullptr) return nullptr;
	if (prev == nullptr) return this;
	return this->prev->find_start();
}

void print_all(Link* p)
{
	while (p) {
		std::cout << "Name: " << p->god_val.name << std::endl;
		std::cout << "Vehicle: " << p->god_val.vehicle << std::endl;
		std::cout << "Weapon: " << p->god_val.weapon << std::endl;
		std::cout << "Mythology: " << mythology_name(p->god_val.mythol) 
			<< std::endl;
		if (p=p->next()) std::cout << std::endl;
	}
}

std::string mythology_name(const Mythology& mythol)
{
	switch (mythol) {
		case Mythology::Greek:
			return "Greek";
		case Mythology::Norse:
			return "Norse";
		case Mythology::Egyptian:
			return "Egyptian";
		default:
			return "";
	}
}
