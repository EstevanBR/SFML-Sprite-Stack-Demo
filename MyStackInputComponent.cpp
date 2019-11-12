#include "Math.hpp"
#include "MyStackInputComponent.hpp"
#include "Input.hpp"
#include "Engine.hpp"
#include "Camera.hpp"

MyStackInputComponent::MyStackInputComponent(const sf::View &view, const UserInput &userInput, Tree &tree, MyStack &myStack):
    _owner(myStack),
    _userInput(userInput),
    _view(view),
    InputComponent<MyStack>(tree, myStack) {
		
}

void MyStackInputComponent::process(float delta) {
    _inputVector.x = 0.f;
    _inputVector.y = 0.f;

    _inputVector.x += (_userInput.left) ? -1.f : 0.f;
    _inputVector.x += (_userInput.right) ? 1.f : 0.f;
    _inputVector.y += (_userInput.up) ? -1.f : 0.f;
    _inputVector.y += (_userInput.down) ? 1.f : 0.f;

    _inputVector = math::normalized(_inputVector);
    _inputVector = math::rotateAroundOrigin(math::degreesToRadians(-_view.getRotation()), _inputVector);
}
