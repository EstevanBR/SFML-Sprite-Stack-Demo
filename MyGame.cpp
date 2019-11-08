#include "MyGame.hpp"
#include "Engine.hpp"
#include "MyStack.hpp"
#include "Collection.hpp"

sf::Texture floorTex;

MyGame::MyGame() {
    main(sf::VideoMode(1280,960), "MyGame", sf::Style::Resize|sf::Style::Close);
}

void MyGame::initialized(Engine &engine) {
    std::cout << "MyGame::initialized" << std::endl;
    const sf::Vector2u windowSize = engine.window.getSize();
    if (floorTex.loadFromFile("tile.png")) {
        floor = std::shared_ptr<sf::Sprite>(new sf::Sprite(floorTex));
        floor->setScale(sf::Vector2f(1.f, 1.f));
        floor->setTextureRect(sf::IntRect(0,0,windowSize.x, windowSize.y));
        floorTex.setRepeated(true);
        engine.graphics.Collection<sf::Drawable>::addObject(floor);
    }
    engine.window.setVerticalSyncEnabled(true);
    engine.window.setFramerateLimit(60);
    engine.window.setKeyRepeatEnabled(false);

    engine.camera.setCenter(windowSize.x / 2, (windowSize.y / 2));
    engine.camera.setSize(
        sf::Vector2f(
            windowSize.x / 3.f,
            windowSize.y * 1.2928932188134525f / 3.f
        )
    );
    
    engine.tree.addObject<MyStack>(std::shared_ptr<MyStack>(new MyStack(engine, sf::Vector2f(windowSize.x / 2,windowSize.y / 2))));
    
    engine.camera.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

    engine.window.setView(engine.camera);
    
    
}

MyGame::~MyGame() {
    std::cout << "MyGame::~MyGame" << std::endl;
}
