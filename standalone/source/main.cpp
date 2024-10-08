#include <cassert>

import stk.input;

using namespace stk;

int main()
{
	c_input input;
	input.add(Keyboard::Space, "space"_h);
	Event event;
	event.type = Event::KeyPressed;
	event.key.code = Keyboard::Space;
	bool res = input.on(event);
	assert(res);
	event.key.code = Keyboard::A;
	res = input.on(event);
	assert(!res);
	assert(input["space"_h] == true);
	event.type = Event::KeyReleased;
	event.key.code = Keyboard::Space;
	input.on(event);
	assert(input["space"_h] == false);
	event.type = Event::KeyPressed;
	input.on(event);
	assert(input["space"_h] == true);
	input.reset();
	assert(input["space"_h] == false);
	return 0;
}
