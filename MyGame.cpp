#include "MyGame.hpp"
#include "Engine.hpp"
#include "MyStack.hpp"
#include "Collection.hpp"

sf::Texture floorTex;

void MyGame::initialized(Engine &engine) {
    std::cout << "MyGame::initialized" << std::endl;
    const sf::Vector2u windowSize = engine.window.getSize();
    if (floorTex.loadFromFile("tile.png")) {
        floor = std::shared_ptr<sf::Sprite>(new sf::Sprite(floorTex));
        floor->move(sf::Vector2f(windowSize.x / 2,-windowSize.x / 2));
        floor->rotate(45.0f);
        floor->setScale(sf::Vector2f(10.f, 10.f));
        floor->setTextureRect(sf::IntRect(0,0,windowSize.x * 2,windowSize.x * 2));
        floorTex.setRepeated(true);
        engine.graphics.Collection<sf::Drawable>::addObject(floor);
    }
    engine.window.setVerticalSyncEnabled(true);
    engine.window.setFramerateLimit(60);
    engine.window.setKeyRepeatEnabled(false);
    
    //engine.window.setView(view);
    //view.setSize(1.0, 0.707);

    myStack = std::shared_ptr<MyStack>(new MyStack(engine.tree, engine.physics, engine.graphics, engine.input));
}

MyGame::~MyGame() {
    myStack.reset();
    std::cout << "MyGame::~MyGame" << std::endl;
}
