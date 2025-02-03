#include "PauseState.h"
#include "Definitions.h"
#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

CPauseState::CPauseState(GameDataRef data) :_data(data)
{
}

CPauseState::~CPauseState()
{
	if (_background != nullptr) delete _background;
	if (_resumeButton != nullptr) delete _resumeButton;
	if (_homeButton != nullptr) delete _resumeButton;
}

void CPauseState::Init()
{
	this->_data->assets.LoadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Resume Button", RESUME_BUTTON);
	this->_data->assets.LoadTexture("Home Button", HOME_BUTTON);

	this->_background = new sf::Sprite(this->_data->assets.GetTexture("Pause Background"));
	this->_resumeButton	 = new sf::Sprite(this->_data->assets.GetTexture("Resume Button"));
	this->_homeButton = new sf::Sprite(this->_data->assets.GetTexture("Home Button"));

	const sf::Vector2f resumeButtonPosition
		= sf::Vector2f((this->_data->window.getSize().x) - (this->_resumeButton->getLocalBounds().size.x / 2), (this->_data->window.getSize().y/3) - (this->_resumeButton->getLocalBounds().size.y / 2));

	const sf::Vector2f homeButtonPosition
		= sf::Vector2f((this->_data->window.getSize().x) - (this->_homeButton->getLocalBounds().size.x / 2), (this->_data->window.getSize().y / 3*2) - (this->_homeButton->getLocalBounds().size.y / 2));

	this->_resumeButton->setPosition(resumeButtonPosition);
	this->_homeButton->setPosition(homeButtonPosition);
}

void CPauseState::HandleInput()
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
		if (this->_data->input.IsSpriteClicked(*_resumeButton, sf::Mouse::Button::Left, this->_data->window))
		{
			this->_data->machine.RemoveState();
		}
		if (this->_data->input.IsSpriteClicked(*_homeButton, sf::Mouse::Button::Left, this->_data->window))
		{
			this->_data->machine.RemoveState();
			this->_data->machine.AddState(StateRef(new CMainMenuState(_data)),true);
		}
	}
}

void CPauseState::Update(float dt)
{
}

void CPauseState::Draw(float dt)
{
	this->_data->window.clear();

	this->_data->window.draw(*_background);
	this->_data->window.draw(*_resumeButton);
	this->_data->window.draw(*_homeButton);

	this->_data->window.display();
}
