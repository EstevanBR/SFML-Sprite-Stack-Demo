#include "MyStackGraphicsComponent.hpp"
#include "SpriteStack.hpp"
#include "MyStack.hpp"

MyStackGraphicsComponent::MyStackGraphicsComponent(Engine &engine, MyStack &owner, MyStackInputComponent &inputComponent):_owner(owner), _inputComponent(inputComponent), GraphicsComponent<MyStack>(engine, owner) {
    _stackSprite = std::shared_ptr<SpriteStack>(new SpriteStack("icon.png", sf::Vector3i(16, 16, 16)));
    engine.graphics.addObject<SpriteStack>(_stackSprite);
}

void MyStackGraphicsComponent::process(float delta) {
    _stackSprite->position = _owner.position;
    _stackSprite->angle = -engine.camera.getRotation();
    //_stackSprite->angle = math::angleTo(inputComponent.inputVector
}
