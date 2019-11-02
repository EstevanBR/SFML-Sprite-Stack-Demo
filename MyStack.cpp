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
    
    inputComponent = std::shared_ptr<MyStackInputComponent>(new MyStackInputComponent(input));
    physicsComponent = std::shared_ptr<MyStackPhysicsComponent>(new MyStackPhysicsComponent(*this, *inputComponent, physics));
    
    
    
    tree.addObject<MyStackInputComponent>(inputComponent);
    tree.addObject<MyStackPhysicsComponent>(physicsComponent);

    graphics.Collection<sf::Drawable>::addObject(std::shared_ptr<sf::Drawable>(this));
}



void MyStack::process(float delta) {
    //_angle += delta * 22.5f;
}

MyStackPhysicsComponent::MyStackPhysicsComponent(MyStack &owner, MyStackInputComponent &inputComponent, Physics &physics):
    _inputComponent(inputComponent),
    PhysicsComponent<MyStack>(owner, physics) {
        auto id = physics.addObject(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(*this, sf::FloatRect(-8,-8,16,16))));
        addObject(physics.getObject(id));
}
void MyStackPhysicsComponent::collidedWithPhysicsComponent(PhysicsComponentBase &physicsComponent) {
    if (dynamic_cast<MyStackPhysicsComponent *>(&physicsComponent) != nullptr) {
        //std::cout << "Collided with a MyStackPhysicsComponent" << std::endl;
    }
}

void MyStackPhysicsComponent::process(float delta) {
    _velocity += _inputComponent.inputVector * 15.f * delta;
    _velocity.x *= _friction.x;
    _velocity.y *= _friction.y;
    _owner.position.x += _velocity.x;
    _owner.position.y += _velocity.y;
}

MyStackInputComponent::MyStackInputComponent(Input &input): InputComponent(input) {
		
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