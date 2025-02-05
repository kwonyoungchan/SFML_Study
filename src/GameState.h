#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
class CGameState:public CState
{
public:
	CGameState(GameDataRef data);
	~CGameState();
	// CState��(��) ���� ��ӵ�
	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;
private:
	GameDataRef _data;
	sf::Sprite* _background;
	sf::Sprite* _pauseButton;

	int turn;
	int gameState;

	// CState��(��) ���� ��ӵ�
	void Pause() override;
	void Resume() override;
};

