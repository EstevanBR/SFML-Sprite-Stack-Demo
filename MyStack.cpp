#include "MyStack.hpp"

#include <memory>
#include <cmath>
#include "Math.hpp"
#include "Tree.hpp"
#include "Graphics.hpp"
#include "Input.hpp"
#include "RectCollisionShape.hpp"
#include "Physics.hpp"

std::string name = "MyStack";
MyStack::MyStack(Engine &engine, sf::Vector2f startingPosition) {
    inputComponent = std::shared_ptr<MyStackInputComponent>(new MyStackInputComponent(engine, *this));
    physicsComponent = std::shared_ptr<MyStackPhysicsComponent>(new MyStackPhysicsComponent(engine, *this, *inputComponent));
    graphicsComponent = std::shared_ptr<MyStackGraphicsComponent>(new MyStackGraphicsComponent(engine, *this));

    position = startingPosition;
}

void MyStack::process(float delta) {

}

MyStackPhysicsComponent::MyStackPhysicsComponent(Engine &engine, MyStack &owner, MyStackInputComponent &inputComponent):
    _inputComponent(inputComponent),
    _owner(owner),
    EntityPhysicsComponent<MyStack>(engine, owner) {
        engine.physics.addObject(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(*this, -8,-8,16,16)));
}

void MyStackPhysicsComponent::collided(CollisionShape &other) {}

void MyStackPhysicsComponent::process(float delta) {
    _velocity += _inputComponent.inputVector * 15.f * delta;
    _velocity.x *= _friction.x;
    _velocity.y *= _friction.y;
    _owner.position.x += _velocity.x;
    _owner.position.y += _velocity.y;
}

MyStackInputComponent::MyStackInputComponent(Engine &engine, MyStack &myStack):
    _owner(myStack),
    InputComponent<MyStack>(engine, myStack) {
		
}

void MyStackInputComponent::process(float delta) {
    _inputVector.x = 0.f;
    _inputVector.y = 0.f;

    _inputVector.x += (engine.input.userInput.left) ? -1.f : 0.f;
    _inputVector.x += (engine.input.userInput.right) ? 1.f : 0.f;
    _inputVector.y += (engine.input.userInput.up) ? -1.f : 0.f;
    _inputVector.y += (engine.input.userInput.down) ? 1.f : 0.f;

    _inputVector = math::normalized(_inputVector);

    engine.camera.rotate(delta);
    engine.window.setView(engine.camera);
}

MyStackGraphicsComponent::MyStackGraphicsComponent(Engine &engine, MyStack &owner):_owner(owner), GraphicsComponent<MyStack>(engine, owner) {
    _stackSprite = std::shared_ptr<SpriteStack>(new SpriteStack("icon.png", sf::Vector3i(16, 16, 16)));
    engine.graphics.addObject<SpriteStack>(_stackSprite);
}

void MyStackGraphicsComponent::process(float delta) {
    _stackSprite->position = _owner.position;
    _stackSprite->angle = -engine.camera.getRotation();
}
