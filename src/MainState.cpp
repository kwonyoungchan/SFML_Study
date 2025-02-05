#include "MainState.h"


void CMainState::Init()
{
}

void CMainState::HandleInput()
{
	if (this->_data == nullptr) return;

	while (const std::optional _event = this->_data->window.pollEvent())
	{
		// 창이 닫혔을 때 window를 종료한다.
		if (_event->is<sf::Event::Closed>())
		{
			this->_data->window.close();
		}
		// 키보드 버튼 이벤트
		if (const auto* keyPressed = _event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				this->_data->window.close();
			}
			OnKeyboardPressed(keyPressed);
		}
		if (const auto* keyReleased = _event->getIf<sf::Event::KeyReleased>())
		{
			OnKeboardReleased(keyReleased);
		}
		// 마우스 클릭 이벤트
		if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>())
		{
			const sf::Vector2f currentMousePosition = 
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window));
			OnMouseButtonPressed(mousePressed, currentMousePosition);
		}
		if (const auto* mouseReleased = _event->getIf<sf::Event::MouseButtonReleased>())
		{
			const sf::Vector2f currentMousePosition =
				static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window));
			OnMouseButtonReleased(mouseReleased, currentMousePosition);
		}
	}
}

void CMainState::Update(float dt)
{
}

void CMainState::Draw(float dt)
{
}

void CMainState::Pause()
{
}

void CMainState::Resume()
{
}


