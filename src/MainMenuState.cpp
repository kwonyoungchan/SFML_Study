#include <sstream>
#include "MainMenuState.h"
#include "Definitions.h"
#include <iostream>

#include "GameState.h"

CMainMenuState::CMainMenuState(GameDataRef data):_data(data)
{
}

CMainMenuState::~CMainMenuState()
{
	if (_background != nullptr) delete _background;
	if (_playButton != nullptr) delete _playButton;
	if (_playButtonOuter != nullptr) delete _playButtonOuter;
	if (_title != nullptr) delete _title;
}

void CMainMenuState::Init()
{
	this->_data->assets.LoadTexture("Background",
		MAIN_MENU_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Play Button",
		MAIN_MENU_PLAY_BUTTON);
	this->_data->assets.LoadTexture("Play Button Outer",
		MAIN_MENU_PLAY_OUTER);
	this->_data->assets.LoadTexture("Game Title",
		MAIN_MENU_TITLE_PATH);

	this->_background= new sf::Sprite(this->_data->assets.GetTexture("Background"));
	this->_playButton = new sf::Sprite(this->_data->assets.GetTexture("Play Button"));
	this->_playButtonOuter = new sf::Sprite(this->_data->assets.GetTexture("Play Button Outer"));
	this->_title = new sf::Sprite(this->_data->assets.GetTexture("Game Title"));

	const sf::Vector2f  playButtonPosition = sf::Vector2f(
		(SCREEN_WIDTH / 2) - (this->_playButton->getGlobalBounds().size.x / 2), 
		(SCREEN_HEIGHT / 2) - (this->_playButton->getGlobalBounds().size.y / 2));

	const sf::Vector2f  playButtonOuterPosition = sf::Vector2f(
		(SCREEN_WIDTH / 2) - (this->_playButtonOuter->getGlobalBounds().size.x / 2),
		(SCREEN_HEIGHT / 2) - (this->_playButtonOuter->getGlobalBounds().size.y / 2));

	const sf::Vector2f  titlePosition = sf::Vector2f(
		(SCREEN_WIDTH / 2) - (this->_title->getGlobalBounds().size.x / 2),
		(300.0f) - (this->_title->getGlobalBounds().size.y * 0.1f));

	this->_playButton->setPosition(playButtonPosition);
	this->_playButtonOuter->setPosition(playButtonOuterPosition);
	this->_title->setPosition(titlePosition);
}


void CMainMenuState::HandleInput()
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
		if (const auto* mousePressed = _event->getIf<sf::Event::MouseButtonPressed>())
		{
			if (mousePressed->button == sf::Mouse::Button::Left)
			{
				sf::Vector2f currentMousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(this->_data->window));
				sf::FloatRect puseButtonBound = this->_playButton->getGlobalBounds();
				
				if (puseButtonBound.contains(currentMousePosition))
				{
					this->_data->machine.AddState(StateRef(new CGameState(_data)), true);
				}

			}
		}
	}
}

void CMainMenuState::Update(float dt)
{
}

void CMainMenuState::Draw(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(*_background);
	this->_data->window.draw(*_playButton);
	//this->_data->window.draw(*_playButtonOuter);
	this->_data->window.draw(*_title);

	this->_data->window.display();


}

void CMainMenuState::Pause()
{
}

void CMainMenuState::Resume()
{
}
