#include "Box.h"
#include <iostream>
using namespace std;
Box::Box()
{
	shape = new sf::RectangleShape({50.f,50.f});
	shape->setOrigin({ shape->getSize().x / 2,shape->getSize().y / 2 });
	// set the shape color to green
	shape->setFillColor(sf::Color(100, 250, 50));

	shape->setPosition({ 250.f,250.f });
	
	position = shape->getPosition();


}
Box::~Box()
{
	delete shape;
	shape = nullptr;
}
void Box::Update(sf::RenderWindow& window)
{
	IControlable::Update(window);
	
	VelocityAlgorithm();
	BoxMoveAlgorithm(window);
	shape->setPosition(position);
	
	window.draw(*shape);

}

void Box::OnMoveRight()
{
	flagR = true;
	
}

void Box::OnMoveLeft()
{
	flagL = true;
}

void Box::OnMoveUp()
{
	flagU = true;
}

void Box::OnMoveDown()
{
	flagD = true;
}

void Box::BoxMoveAlgorithm(sf::RenderWindow& window)
{
	const sf::Vector2f curPosition = position;
	const sf::Vector2f shapeSize = shape->getSize();
	const sf::Vector2u windowSize = window.getSize();

	cout << velocity.x << '\t' << velocity.y << endl;
	position = curPosition + velocity;
	shape->setPosition(position);
	
	
	// 박스가 윈도우 범위 벗어났는지 체크 
	if (curPosition.x + (shapeSize.x / 2) > windowSize.x)
	{
		position.x = windowSize.x - (shapeSize.x / 2);
	}
	if (curPosition.x - (shapeSize.x / 2) < 0)
	{
		position.x = (shapeSize.x / 2);
	}
	if (curPosition.y + (shapeSize.y / 2) > windowSize.y)
	{
		position.y = windowSize.y - (shapeSize.y / 2);
	}
	if (curPosition.y - (shapeSize.y / 2) < 0)
	{
		position.y = shapeSize.y / 2;
	}


}

void Box::AddVelocity(float addX, float addY)
{
	if (abs(velocity.x) <= maxSpeed) velocity.x += addX;
	if (abs(velocity.y) <= maxSpeed) velocity.y += addY;
}



void Box::VelocityAlgorithm()
{
	// 방향키 입력이 들어왔는지 체크한다. 
	// 만약 입력이 들어왔다면 
	if (flagR) AddVelocity(0.001f, 0);
	if (flagL) AddVelocity(-0.001f, 0);
	if (flagU) AddVelocity(0, -0.001f);
	if (flagD) AddVelocity(0, +0.001f);

	if (!flagR || !flagL)
	{
		if (abs(velocity.x) > 0.000001f)
		{
			if (velocity.x > 0) velocity.x -= 0.00005f;
			else velocity.x += 0.00005f;
		}
		else
		{
			velocity.x = 0;
		}
	}

	if (!flagU || !flagD)
	{
		if (abs(velocity.y) > 0.000001f)
		{
			if (velocity.y > 0) velocity.y -= 0.00005f;
			else velocity.y += 0.00005f;
		}
		else
		{
			velocity.y = 0;
		}
	}

	flagR = false;
	flagL = false;
	flagU = false;
	flagD = false; 
}
