// �÷��̾� ��Ʈ�ѷ� �������̽� 
#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class IControlable
{
public:
	virtual void Update(sf::RenderWindow& window);

public:
	// �÷��̾� �Է� �ݹ� �Լ� 
	virtual void OnMoveRight() = 0;
	virtual void OnMoveLeft() =0; 
	virtual void OnMoveUp() =0;
	virtual void OnMoveDown() =0;
};