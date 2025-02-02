#include <sstream>
#include "GameState.h"
#include "Definitions.h"
#include <iostream>

CGameState::CGameState(GameDataRef data) :_data(data)
{
}

CGameState::~CGameState()
{
	if (_background != nullptr) delete _background;
	if (_pauseButton != nullptr) delete _pauseButton;
}

void CGameState::Init()
{
	gameState = STATE_PLAYING;
	turn = PLAYER_PIECE;

	this->_data->assets.LoadTexture("Pause Button", PAUSE_BUTTON);

	_background = new sf::Sprite(this->_data->assets.GetTexture("Background"));
	_pauseButton = new sf::Sprite(this->_data->assets.GetTexture("Pause Button"));

	const sf::Vector2f pauseButtonPosition =
		sf::Vector2f(
			this->_data->window.getSize().x - _pauseButton->getLocalBounds().size.x,
			_pauseButton->getPosition().y);
	_pauseButton->setPosition(pauseButtonPosition);
}


void CGameState::HandleInput()
{
	while (const std::optional _event = this->_data->window.pollEvent())
	{
		if (const auto* keyPressed = _event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				this->_data->window.close();
			}
		}
		if (this->_data->input.IsSpriteClicked(*_pauseButton, sf::Mouse::Button::Left, this->_data->window))
		{
			std::cout << "Pause The Game" << std::endl;
		}
	}
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
