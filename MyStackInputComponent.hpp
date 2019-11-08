#ifndef MY_STACK_INPUT_COMPONENT_HPP
#define MY_STACK_INPUT_COMPONENT_HPP

#include "InputComponent.hpp"

class MyStack;

class MyStackInputComponent: public InputComponent<MyStack> {
private:
	friend class MyStack;

	MyStack &_owner;

	sf::Vector2f _inputVector = sf::Vector2f(0,0);
	MyStackInputComponent(Engine &engine, MyStack &owner);
	void process(float delta) override;
	
public:
	const sf::Vector2f &inputVector = _inputVector;
};

#endif