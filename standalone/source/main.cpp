#include <cassert>

import stk.input;

using namespace stk;

int main()
{
	c_input input;
	input.add(sf::Keyboard::Space, "space"_h);
	sf::Event event;
	event.type = sf::Event::KeyPressed;
	event.key.code = sf::Keyboard::Space;
	bool res = input.on(event);
	assert(res);
	event.key.code = sf::Keyboard::A;
	res = input.on(event);
	assert(!res);
	assert(input["space"_h] == true);
	event.type = sf::Event::KeyReleased;
	event.key.code = sf::Keyboard::Space;
	input.on(event);
	assert(input["space"_h] == false);
	return 0;
}
