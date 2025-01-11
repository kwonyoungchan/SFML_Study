#pragma once 
#include "Controller.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Box :public IControlable
{
public:
	Box();
	~Box();
public: 
	void Update(sf::RenderWindow& window) override;


	// IControlable을(를) 통해 상속됨
	void OnMoveRight() override;

	void OnMoveLeft() override;

	void OnMoveUp() override;

	void OnMoveDown() override;
private:
	// 박스의 제원정보 
	bool flagR, flagL, flagU, flagD;
	float acc = 0.02f;
	float friction = 0.05f;
	float maxSpeed = 0.1f;
	sf::Vector2f velocity;
	sf::Vector2f lastVelocity;
	sf::Vector2f position;
	sf::RectangleShape* shape;

public:
	void BoxMoveAlgorithm(sf::RenderWindow& window);
	void AddVelocity(float addX, float addY);
	void VelocityAlgorithm();
};