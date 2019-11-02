#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include <cmath>
#include "SpriteStack.hpp"
#include "Input.hpp"
#include "InputComponent.hpp"
#include "PhysicsComponent.hpp"

class Tree;
class Graphics;
class Input;
class UserInput;
class MyStack;

class MyStackPhysicsComponent;
class MyStackInputComponent;

class MyStackPhysicsComponent: public PhysicsComponent<MyStack> {
	friend class MyStack;
	MyStackInputComponent &_inputComponent;
	sf::Vector2f _velocity;
	sf::Vector2f _friction = sf::Vector2f(0.9f, 0.9f);
	MyStackPhysicsComponent(MyStackInputComponent &inputComponent, Physics &physics, MyStack &myStack);
	void process(float delta) override;
public:
	const sf::Vector2f &velocity = _velocity;
	const sf::Vector2f &fricton = _friction;
};

class MyStackInputComponent: public InputComponent<MyStack> {
private:
	friend class MyStack;
	sf::Vector2f _inputVector = sf::Vector2f(0,0);
	MyStackInputComponent(Input &input, MyStack &myStack);
	void process(float delta) override;
public:
	const sf::Vector2f &inputVector = _inputVector;
};

class MyStack: public SpriteStack {
private:
	
	

	std::string name = "MyStack";

	std::shared_ptr<MyStackInputComponent> inputComponent;
	std::shared_ptr<MyStackPhysicsComponent> physicsComponent;
public:
	MyStack(Tree &tree, Physics &physics, Graphics &graphics, Input &input);
	void process(float delta) override;
};

#endif