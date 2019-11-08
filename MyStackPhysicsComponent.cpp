#include "MyStackPhysicsComponent.hpp"
#include "MyStack.hpp"
#include "RectCollisionShape.hpp"
#include "MyStackInputComponent.hpp"
#include "Engine.hpp"
#include "Physics.hpp"


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