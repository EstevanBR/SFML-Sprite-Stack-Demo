#ifndef DEATH_ZONE_HPP
#define DEATH_ZONE_HPP

#include <memory>


#include "Physics.hpp"
#include "PhysicsComponent.hpp"

class PhysicsComponent;

class DeathZone {
private:
    friend class Game;

    std::shared_ptr<PhysicsComponent> physicsComponent;
    DeathZone(float radius, Physics &physics) {
        PhysicsComponent(physics);
        
    }

};

#endif