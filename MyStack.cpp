#include "MyStack.hpp"

#include <memory>
#include <cmath>
#include "Tree.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "RectCollisionShape.hpp"
#include "Physics.hpp"

std::string name = "MyStack";
MyStack::MyStack(Tree &tree, Physics &physics, Graphics &graphics, Input &input): SpriteStack("icon.png", sf::Vector3i(16, 16, 16)) {
    tree.addObject(std::shared_ptr<Node>(this));
    
    inputComponent = std::shared_ptr<MyStackInputComponent>(new MyStackInputComponent(input, *this));
    physicsComponent = std::shared_ptr<MyStackPhysicsComponent>(new MyStackPhysicsComponent(*inputComponent, physics, *this));
    
    

    tree.addObject<MyStackInputComponent>(inputComponent);
    tree.addObject<MyStackPhysicsComponent>(physicsComponent);

    graphics.Collection<sf::Drawable>::addObject(std::shared_ptr<sf::Drawable>(this));
}

void MyStack::process(float delta) {
    //_angle += delta * 22.5f;
}

MyStackPhysicsComponent::MyStackPhysicsComponent(MyStackInputComponent &inputComponent, Physics &physics, MyStack &myStack):
    _inputComponent(inputComponent),
    PhysicsComponent<MyStack>(physics, myStack) {
        auto id = physics.addObject(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(sf::FloatRect(-8,-8,16,16))));
        addObject(physics.getObject(id));
}

void MyStackPhysicsComponent::process(float delta) {
    _velocity += _inputComponent.inputVector * 15.f * delta;
    _velocity.x *= _friction.x;
    _velocity.y *= _friction.y;
    owner.position.x += _velocity.x;
    owner.position.y += _velocity.y;
}

MyStackInputComponent::MyStackInputComponent(Input &input, MyStack &myStack): InputComponent<MyStack>(input, myStack) {
		
}

void MyStackInputComponent::process(float delta) {
    _inputVector.x = 0.f;
    _inputVector.y = 0.f;

    _inputVector.x += (subsystem.userInput.left) ? -1.f : 0.f;
    _inputVector.x += (subsystem.userInput.right) ? 1.f : 0.f;
    _inputVector.y += (subsystem.userInput.up) ? -1.f : 0.f;
    _inputVector.y += (subsystem.userInput.down) ? 1.f : 0.f;

    if (_inputVector.x > 0.f || _inputVector.y > 0.f) {
        auto s = sqrtf(powf(_inputVector.x, 2.f) + powf(_inputVector.y, 2.f));
        _inputVector.x /= s;
        _inputVector.y /= s;
    }  
}