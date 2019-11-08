#include "MyStack.hpp"

#include "MyStackGraphicsComponent.hpp"
#include "MyStackInputComponent.hpp"
#include "MyStackPhysicsComponent.hpp"


MyStack::MyStack(Engine &engine, sf::Vector2f startingPosition) {
    inputComponent = std::shared_ptr<MyStackInputComponent>(new MyStackInputComponent(engine, *this));
    physicsComponent = std::shared_ptr<MyStackPhysicsComponent>(new MyStackPhysicsComponent(engine, *this, *inputComponent));
    graphicsComponent = std::shared_ptr<MyStackGraphicsComponent>(new MyStackGraphicsComponent(engine, *this, *inputComponent));

    position = startingPosition;
}

void MyStack::process(float delta) {

}
