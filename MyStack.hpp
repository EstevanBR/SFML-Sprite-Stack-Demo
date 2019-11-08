#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include <cmath>

#include "Node.hpp"
#include "Object2D.hpp"

class Engine;
class MyStack;

class MyStackPhysicsComponent;
class MyStackInputComponent;
class MyStackGraphicsComponent;

class MyStack: public Object2D, public Node {
private:
	std::shared_ptr<MyStackInputComponent> inputComponent;
	std::shared_ptr<MyStackPhysicsComponent> physicsComponent;
	std::shared_ptr<MyStackGraphicsComponent> graphicsComponent;
	void process(float delta) override;
public:
	MyStack(Engine &engine, sf::Vector2f startingPosition = sf::Vector2f(0,0));
};

#endif