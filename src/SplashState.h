#pragma once
#include <SFML/Graphics.hpp>
#include "BaseState.h"
#include "Game.h"
class CSplashState :public CBaseState
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

	// CState��(��) ���� ��ӵ�
	void Pause() override;
	void Resume() override;

	// CMainState��(��) ���� ��ӵ�
	void OnKeyboardPressed(const sf::Event::KeyPressed* pressedEvent) override;
	void OnKeboardReleased(const sf::Event::KeyReleased* releasedEvent) override;
	void OnMouseButtonPressed(const sf::Event::MouseButtonPressed* pressedEvent, const sf::Vector2f pressedPosition) override;
	void OnMouseButtonReleased(const sf::Event::MouseButtonReleased* releasedEvent, const sf::Vector2f releasedPosition) override;
};

