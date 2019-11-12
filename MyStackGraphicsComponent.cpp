#include "MyStackGraphicsComponent.hpp"
#include "SpriteStack.hpp"
#include "MyStack.hpp"
#include "Graphics.hpp"
#include "Engine.hpp"
#include "Camera.hpp"

MyStackGraphicsComponent::MyStackGraphicsComponent(const sf::View &view, Graphics &graphics, Tree &tree, MyStack &owner, MyStackInputComponent &inputComponent):
    _owner(owner),
    _inputComponent(inputComponent),
    _view(view),
    GraphicsComponent<MyStack>(graphics, tree, owner) {
    _stackSprite = std::shared_ptr<SpriteStack>(new SpriteStack("icon.png", sf::Vector3i(16, 16, 16)));
    _stackSprite->setPosition(_owner.getPosition());
    graphics.addObject<SpriteStack>(_stackSprite);
}

void MyStackGraphicsComponent::process(float delta) {
    _stackSprite->setPosition(_owner.getPosition());
}
