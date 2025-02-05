#pragma once
#include <SFML/Graphics.hpp>
#include "BaseState.h"
#include "Game.h"
class CGameState:public CBaseState
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
	sf::Sprite* _background;
	sf::Sprite* _pauseButton;

	int turn;
	int gameState;

	// CState��(��) ���� ��ӵ�
	void Pause() override;
	void Resume() override;


	// CMainState��(��) ���� ��ӵ�
	void OnKeyboardPressed(const sf::Event::KeyPressed* pressedEvent) override;

	void OnKeboardReleased(const sf::Event::KeyReleased* releasedEvent) override;

	void OnMouseButtonPressed(const sf::Event::MouseButtonPressed* pressedEvent, const sf::Vector2f pressedPosition) override;

	void OnMouseButtonReleased(const sf::Event::MouseButtonReleased* releasedEvent, const sf::Vector2f releasedPosition) override;

};

