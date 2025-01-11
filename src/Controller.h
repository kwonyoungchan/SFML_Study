// 플레이어 컨트롤러 인터페이스 
#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class IControlable
{
public:
	virtual void Update(sf::RenderWindow& window);

public:
	// 플레이어 입력 콜백 함수 
	virtual void OnMoveRight() = 0;
	virtual void OnMoveLeft() =0; 
	virtual void OnMoveUp() =0;
	virtual void OnMoveDown() =0;
};