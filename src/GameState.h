#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
class CGameState:public CState
{
public:
	CGameState(GameDataRef data);
	~CGameState();
	// CState을(를) 통해 상속됨
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

	// CState을(를) 통해 상속됨
	void Pause() override;
	void Resume() override;
};

