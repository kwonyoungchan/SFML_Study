#pragma once
#include <SFML/Graphics.hpp>
#include "../src/State.h"
#include "../src/Game.h"
class CSplashState :public CState
{
public:
	CSplashState(GameDataRef data);
	~CSplashState();

	// CState��(��) ���� ��ӵ�
	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;
private:
	GameDataRef _data;
	sf::Clock _clock;

	sf::Sprite* _background;
};

