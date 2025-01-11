#include "Controller.h"


void IControlable::Update(sf::RenderWindow& window)
{
	// Ű���� �Է��� �޴´�.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		OnMoveRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		OnMoveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		OnMoveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		OnMoveDown();
	}
}
