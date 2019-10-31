#ifndef MY_GAME_HPP
#define MY_GAME_HPP

#include <SFML/Graphics.hpp>
#include "Engine.hpp"
#include "Game.hpp"

class MyStack;

class MyGame: public Game {
private:
	friend class Game;
	std::shared_ptr<MyStack> myStack;
	std::shared_ptr<sf::Sprite> floor;
	
	void initialized(Engine &engine) override;
public:
	~MyGame();
};

#endif