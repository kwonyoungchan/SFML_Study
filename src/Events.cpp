#include "Events.h"
#include <SFML/Window.hpp>
#include <iostream>

#define REPEAT_KEY 0
void CheckKeyboardEvents()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
#if(REPEAT_KEY ==1)
		static bool keyPressed ;
		if()
#endif
		
		std::cout << "LeftKey Pressed" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		static bool keyPressed = false;
		std::cout << "Right Key Pressed" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		static bool keyPressed = false;
		std::cout << "Up Key Pressed" << std::endl;
	}
}
