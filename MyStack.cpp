#include "MyStack.hpp"

#include "Input.hpp"

#include "MyStackGraphicsComponent.hpp"
#include "MyStackInputComponent.hpp"
#include "MyStackPhysicsComponent.hpp"
#include "Camera.hpp"


MyStack::MyStack(Engine &engine) {
    

    inputComponent = std::shared_ptr<MyStackInputComponent>(new MyStackInputComponent(engine.camera, engine.input.userInput, engine.tree, *this));
    physicsComponent = std::shared_ptr<MyStackPhysicsComponent>(new MyStackPhysicsComponent(engine.physics, engine.tree, *this, inputComponent->inputVector));
    graphicsComponent = std::shared_ptr<MyStackGraphicsComponent>(new MyStackGraphicsComponent(engine.camera, engine.graphics, engine.tree, *this, *inputComponent));
}

void MyStack::process(float delta) {

}
