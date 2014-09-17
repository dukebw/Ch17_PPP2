#include <iostream>
#include "Link.h"

int main()
{
	Link* norse_gods{new Link{"Thor", nullptr, nullptr}};
	norse_gods = norse_gods->insert(new Link{"Odin"});
	norse_gods = norse_gods->insert(new Link{"Freia"});
	norse_gods = norse_gods->insert(new Link{"Zeus"});

	Link* greek_gods{new Link{"Hera", nullptr, nullptr}};
	greek_gods = greek_gods->insert(new Link{"Athena"});
	greek_gods = greek_gods->insert(new Link{"Mars"});
	greek_gods = greek_gods->insert(new Link{"Poseidon"});

	Link* p{greek_gods->find("Mars")};
	if (p) p->value = "Ares";

	Link* p2 = norse_gods->find("Zeus");
	if (p) {
		if (p2 == norse_gods) norse_gods = p2->next();
		p2->erase();
		greek_gods = greek_gods->insert(p2);
	}

	print_all(norse_gods);
	std::cout << '\n';

	print_all(greek_gods);
	std::cout << '\n';
	return 0;
}
