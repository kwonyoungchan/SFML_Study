#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class CMainMenuState: public CState
{
public:
	CMainMenuState(GameDataRef data);
	~CMainMenuState();
	// CState을(를) 통해 상속됨
	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;
private:
	GameDataRef _data;
	sf::Sprite* _background;
	sf::Sprite* _playButton;
	sf::Sprite* _title;
	sf::Sprite* _playButtonOuter;

};

