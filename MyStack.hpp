#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>

#include "Node.hpp"

class Engine;
class MyStack;

class MyStackPhysicsComponent;
class MyStackInputComponent;
class MyStackGraphicsComponent;

class MyStack: public sf::Transformable, public Node {
private:
	std::shared_ptr<MyStackInputComponent> inputComponent;
	std::shared_ptr<MyStackPhysicsComponent> physicsComponent;
	std::shared_ptr<MyStackGraphicsComponent> graphicsComponent;
	void process(float delta) override;
public:
	MyStack(Engine &engine);
};

#endif