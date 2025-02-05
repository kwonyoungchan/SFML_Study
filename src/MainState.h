#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class CMainState: public CState
{
public:
	CMainState() {}
	~CMainState() {}
	// CState��(��) ���� ��ӵ�
	void Init() override;
	void HandleInput() override;
	void Update(float dt) override;
	void Draw(float dt) override;
	void Pause() override;
	void Resume() override;
public:
	virtual void OnKeyboardPressed(const sf::Event::KeyPressed* pressedEvent)=0;
	virtual void OnKeboardReleased(const sf::Event::KeyReleased* releasedEvent) =0;

	virtual void OnMouseButtonPressed(
		const sf::Event::MouseButtonPressed* pressedEvent, 
		const sf::Vector2f pressedPosition) =0;

	virtual void OnMouseButtonReleased(
		const sf::Event::MouseButtonReleased* releasedEvent, 
		const sf::Vector2f releasedPosition) =0;
protected:
	GameDataRef _data;
};

