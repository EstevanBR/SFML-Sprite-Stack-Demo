#ifndef MY_STACK_GRAPHICS_COMPONENT_HPP
#define MY_STACK_GRAPHICS_COMPONENT_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include "GraphicsComponent.hpp"

class Engine;
class MyStack;
class SpriteStack;

class MyStackInputComponent;

class MyStackGraphicsComponent: public GraphicsComponent<MyStack> {
	friend class MyStack;

	MyStack &_owner;
	const MyStackInputComponent &_inputComponent;
	const sf::View &_view;

	std::shared_ptr<SpriteStack> _stackSprite;
	MyStackGraphicsComponent(const sf::View &view, Graphics &graphics, Tree &tree, MyStack &owner, MyStackInputComponent &inputComponent);
	void process(float delta) override;
};

#endif