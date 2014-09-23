#include <string>
#include <iostream>
#include "Link_single.h"

bool operator>(const Link& a, const Link& b)
{
	return (a.god_val.name > b.god_val.name) ? true : false;
}

Link* Link::add(Link* n) // insert n after this Link; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	if (succ) n->succ = succ;
	succ = n;
	return n;
}

// returns nullptr if nothing is erased, successor of erased link if successor
// exists, and nullptr if last link is erased
Link* Link::erase(const std::string& s)
{
	if (this == nullptr) return nullptr;
	if (god_val.name == s) {
		if (succ) {
			Link* begin{nullptr};
			begin = succ;
			succ = nullptr;
			return begin;
		}
		return nullptr;
	}	
	else if (succ) {
		if (succ->god_val.name == s) {
			succ = succ->succ;
			if (succ) return succ;
			return nullptr;
		}
		else return succ->erase(s);
	}
	else return nullptr;
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

Link* Link::add_ordered(Link* n) // assumes already ordered
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	if (*n > *this) {
		if (succ) {
			if (*succ > *n) {
				n->succ = succ;
				succ = n;
				return n;
			}
			else return succ->add_ordered(n);
		}
		else return add(n);
	}
	else {
		n->succ = this;
		return n;
	}
}

// move n positions in list; return nullptr for "not found"
const Link* Link::advance(int n) const
{
	const Link* p{this};
	if (p == nullptr) return nullptr;
	if (n < 0) return nullptr;
	if (n > 0) {
		while (n--) {
			if (p->succ == nullptr) return nullptr;
			p = p->succ;
		}
	}
	return p;
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
