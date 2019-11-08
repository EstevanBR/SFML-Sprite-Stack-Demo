#ifndef MY_STACK_PHYSICS_COMPONENT_HPP
#define MY_STACK_PHYSICS_COMPONENT_HPP

#include "PhysicsComponent.hpp"

class MyStack;
class MyStackInputComponent;

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

#endif