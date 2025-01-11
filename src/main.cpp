#include <SFML/Graphics.hpp>
#include <iostream>
#include "Box.h"
#include "Events.h"


int main()
{
	// 윈도우 설정
	sf::RenderWindow window(sf::VideoMode({ 800,600 }), "Rendering window");

	Box box; 
	// open close 로직 
	while (window.isOpen())
	{
		window.clear();
		box.Update(window);
		window.display();
	}
	// 
	return 0;
};
	
