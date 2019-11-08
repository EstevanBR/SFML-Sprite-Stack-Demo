#include "Math.hpp"
#include "MyStackInputComponent.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "Camera.hpp"

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
    _inputVector = math::rotateAroundOrigin(math::degreesToRadians(-engine.camera.getRotation()), _inputVector);

    engine.camera.rotate(15 * delta);

    engine.window.setView(engine.camera);
}