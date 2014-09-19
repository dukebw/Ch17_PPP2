#include <iostream>
#include "Link.h"

int main()
{
	God god_temp{God{"Thor", "A chariot pulled by two goats (that he eats and"
		" resurrects", "Mountain-crushing hammer called Mjolnir", 
		Mythology::Norse}};
	Link* norse_gods{new Link{god_temp, nullptr, nullptr}};
	god_temp = God{"Odin", "Eight-legged flying horse called Sleipnir", 
		"Spear called Gungnir", Mythology::Norse};
	norse_gods = norse_gods->add_ordered(new Link{god_temp});
	god_temp = God{"Freia", "A chariot pulled by two cats", "A feathered cloak", 
		Mythology::norse};
	norse_gods = norse_gods->add_ordered(new Link{god_temp});

	god_temp = God{"Zeus", "The Chariot of Zeus", "Thunderbolts", 
		Mythology::Greek};
	Link* greek_gods{new Link{god_temp, nullptr, nullptr}};
	god_temp = God{"Athena", "None", "An extremely long spear", Mythology::Greek};
	greek_gods = greek_gods->insert(new Link{god_temp});
	god_temp = God{"Ares", "His war chariot", "A spear and helmet", 
		Mythology::greek};
	greek_gods = greek_gods->insert(new Link{god_temp});
	god_temp = God{"Poseidon", "A chariot pulled by a winged hippocampus, or"
		" horses that can ride on the sea itself", "A trident", 
			Mythology::Greek};
	greek_gods = greek_gods->insert(new Link{god_temp});

	god_temp = God{"Osiris", "None", "A crook and flail", Mythology::Egyptian};
	Link* egypt_gods{new Link{god_temp, nullptr, nullptr}};
	print_all(norse_gods);
	std::cout << '\n';

	print_all(greek_gods);
	std::cout << '\n';
	return 0;
}
