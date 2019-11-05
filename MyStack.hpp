#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include <cmath>

#include "SpriteStack.hpp"

#include "InputComponent.hpp"
#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"

class Engine;
class MyStack;

class MyStackPhysicsComponent;
class MyStackInputComponent;
class MyStackGraphicsComponent;

class MyStackPhysicsComponent: public EntityPhysicsComponent<MyStack> {
	friend class MyStack;

	MyStack &_owner;

	MyStackInputComponent &_inputComponent;
	sf::Vector2f _velocity;
	sf::Vector2f _friction = sf::Vector2f(0.9f, 0.9f);
	MyStackPhysicsComponent(Engine &engine, MyStack &owner, MyStackInputComponent &inputComponent);
	void process(float delta) override;
	void collided(CollisionShape &other) override;
public:
	const sf::Vector2f &velocity = _velocity;
	const sf::Vector2f &fricton = _friction;
};

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

class MyStackGraphicsComponent: public GraphicsComponent<MyStack> {
	friend class MyStack;

	MyStack &_owner;
	const MyStackInputComponent &_inputComponent;
	
	std::shared_ptr<SpriteStack> _stackSprite;
	MyStackGraphicsComponent(Engine &engine, MyStack &owner, MyStackInputComponent &inputComponent);
	void process(float delta) override;
};

class MyStack: public Object2D, public Node {
private:
	friend class MyStackPhysicsComponent;

	std::shared_ptr<MyStackInputComponent> inputComponent;
	std::shared_ptr<MyStackPhysicsComponent> physicsComponent;
	std::shared_ptr<MyStackGraphicsComponent> graphicsComponent;
	void process(float delta) override;
public:
	MyStack(Engine &engine, sf::Vector2f startingPosition = sf::Vector2f(0,0));
};

#endif