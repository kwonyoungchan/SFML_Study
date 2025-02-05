#include "SplashState.h"
#include "Definitions.h"
#include <sstream>
#include <iostream>

#include "MainMenuState.h"

CSplashState::CSplashState(GameDataRef data)
{
	_data = data;
}

CSplashState::~CSplashState()
{
	if (_background != nullptr)
	{
		delete _background;
	}
}

void CSplashState::Init()
{
	this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
	_background = new sf::Sprite(this->_data->assets.GetTexture("Splash State Background"));
}

void CSplashState::HandleInput()
{
	while (const std::optional event = this->_data->window.pollEvent() )
	{
		if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
		{
			if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
			{
				this->_data->window.close();
			}
			
		}
	}
}

void CSplashState::Update(float dt)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		// Switch to the Main Menu
		this->_data->machine.AddState(StateRef(new CMainMenuState(_data)), true);
	}
}

void CSplashState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(*_background);
	this->_data->window.display();

}

void CSplashState::Pause()
{
}

void CSplashState::Resume()
{
}
