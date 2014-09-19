#include <string>
#include <iostream>
#include "Link.h"

bool operator>(const Link* a, const Link* b)
{
	if (b == nullptr) return true;
	if (a == nullptr) return false;
	return (a->god_val->name > b->god_val->name) ? true : false;
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
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const std::string& s) const
{
	const Link* p{this};
	while (p) {
		if (p->value == s) return p;
		p = p->succ;
	}
	return nullptr;
}

Link* add_ordered(Link* n) // assumes already ordered
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	if (n > this) 
		return (succ) ? succ::add_ordered(n) : add(n);
	else return insert(n);
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

void print_all(Link* p)
{
	std::cout << "{ ";
	while (p) {
		std::cout << p->value;
		if (p=p->next()) std::cout << ", ";
	}
	std::cout << " }";
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
