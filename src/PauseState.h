#pragma once
#include "SFML/Graphics.hpp"
#include "State.h"
#include "Game.h"
class CPauseState: public CState
{
public:
	CPauseState(GameDataRef data);
	~CPauseState();
	// CState��(��) ���� ��ӵ�
	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;
private:
	GameDataRef _data;
	sf::Sprite* _background;
	sf::Sprite* _resumeButton;
	sf::Sprite* _homeButton;


	// CState��(��) ���� ��ӵ�
	void Pause() override;

	void Resume() override;

};

