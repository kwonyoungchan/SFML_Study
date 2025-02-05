#include <sstream>
#include "GameState.h"
#include "Definitions.h"
#include <iostream>

#include "PauseState.h"

CGameState::CGameState(GameDataRef data)
{
	_data = data;
}

CGameState::~CGameState()
{
	if (_background != nullptr) delete _background;
	if (_pauseButton != nullptr) delete _pauseButton;
}

void CGameState::Init()
{
	this->_data->assets.LoadTexture("GameBackground",GAME_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);

	_background = new sf::Sprite(this->_data->assets.GetTexture("GameBackground"));
	_pauseButton = new sf::Sprite(this->_data->assets.GetTexture("Pause Button"));

	const sf::Vector2f pauseButtonPosition =
		sf::Vector2f(
			this->_data->window.getSize().x - (_pauseButton->getLocalBounds().size.x),
			_pauseButton->getPosition().y);
	_pauseButton->setPosition(pauseButtonPosition);
}


void CGameState::HandleInput()
{
	CBaseState::HandleInput();
}

void CGameState::Update(float dt)
{
}

void CGameState::Draw(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(*_background);
	this->_data->window.draw(*_pauseButton);


	this->_data->window.display();


}

void CGameState::Pause()
{
}

void CGameState::Resume()
{
}

void CGameState::OnKeyboardPressed(const sf::Event::KeyPressed* pressedEvent)
{
}


void CGameState::OnKeboardReleased(const sf::Event::KeyReleased* releasedEvent)
{
}


void CGameState::OnMouseButtonPressed(const sf::Event::MouseButtonPressed* pressedEvent, const sf::Vector2f pressedPosition)
{
	if (pressedEvent->button == sf::Mouse::Button::Left)
	{
		sf::FloatRect puseButtonBound = this->_pauseButton->getGlobalBounds();

		if (puseButtonBound.contains(pressedPosition))
		{
			this->_data->machine.AddState(StateRef(new CPauseState(_data)), false);
		}
	}
}


void CGameState::OnMouseButtonReleased(const sf::Event::MouseButtonReleased* releasedEvent, const sf::Vector2f releasedPosition)
{
}



