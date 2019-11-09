#ifndef MY_GAME_HPP
#define MY_GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "Engine.hpp"
#include "Game.hpp"

class MyStack;

class MyGame: public Game {
private:
	friend class Game;

	std::shared_ptr<sf::Sprite> _floor;
	
	void initialized(Engine &engine) override;
public:
	MyGame();
	~MyGame();
};

#endif