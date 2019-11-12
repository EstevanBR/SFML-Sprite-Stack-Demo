#ifndef MY_STACK_INPUT_COMPONENT_HPP
#define MY_STACK_INPUT_COMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "InputComponent.hpp"

class UserInput;
class MyStack;

class MyStackInputComponent: public InputComponent<MyStack> {
private:
	friend class MyStack;

	MyStack &_owner;
	const UserInput &_userInput;
	sf::Vector2f _inputVector = sf::Vector2f(0,0);
	const sf::View &_view;
	MyStackInputComponent(const sf::View &view, const UserInput &userInput, Tree &tree, MyStack &owner);
	void process(float delta) override;
	
public:
	const sf::Vector2f &inputVector = _inputVector;
};

#endif