#include "MyStackPhysicsComponent.hpp"
#include "MyStack.hpp"
#include "RectCollisionShape.hpp"
#include "MyStackInputComponent.hpp"
#include "Tree.hpp"
#include "Physics.hpp"


MyStackPhysicsComponent::MyStackPhysicsComponent(Physics &physics, Tree &tree, MyStack &owner, const sf::Vector2f &inputVector):
    _inputVector(inputVector),
    _owner(owner),
    EntityPhysicsComponent<MyStack>(physics, tree, owner) {
        physics.addObject(std::shared_ptr<RectCollisionShape>(new RectCollisionShape(*this, -8,-8,16,16)));
}

void MyStackPhysicsComponent::collided(CollisionShape &other) {}

void MyStackPhysicsComponent::process(float delta) {
    _velocity += _inputVector * 15.f * delta;
    _velocity.x *= _friction.x;
    _velocity.y *= _friction.y;
    _owner.setPosition(_owner.getPosition() + _velocity);
}