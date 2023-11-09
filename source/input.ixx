export module stk.input;

import <SFML/Window.hpp>;
import std.core;
import stk.hash;
import stk.math;

namespace stk
{
	export class c_input
	{
	public:
		void add(sf::Keyboard::Key key, c_hash action)
		{
			m_keys[key] = action;
			m_state[action] = false;
		}

		bool operator[](c_hash action) const
		{
			auto it = m_state.find(action);
			if (it != m_state.end())
			{
				return it->second;
			}
			return false;
		}

		bool on(sf::Event const& event)
		{
			if (event.type == sf::Event::KeyPressed)
			{
				auto it = m_keys.find(event.key.code);
				if (it != m_keys.end())
				{
					m_state[it->second] = true;
					return true;
				}
				return false;
			}
			else if (event.type == sf::Event::KeyReleased)
			{
				auto it = m_keys.find(event.key.code);
				if (it != m_keys.end())
				{
					m_state[it->second] = false;
					return true;
				}
				return false;
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				m_mouse = { event.mouseMove.x, event.mouseMove.y };
				return true;
			}
			return false;
		}

		void reset()
		{
			for (auto& [_, state] : m_state)
			{
				state = false;
			}
		}

		c_vec2i mouse() const
		{
			return m_mouse;
		}

	private:
		std::unordered_map<sf::Keyboard::Key, c_hash> m_keys;
		std::unordered_map<c_hash, bool, s_hash_hasher> m_state;
		c_vec2i m_mouse;
	};
}