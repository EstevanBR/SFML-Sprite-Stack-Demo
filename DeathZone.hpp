#ifndef DEATH_ZONE_HPP
#define DEATH_ZONE_HPP

#include <memory>


#include "Physics.hpp"
#include "PhysicsComponent.hpp"

class PhysicsComponentBase;

class DeathZone {
private:
    friend class Game;

    std::shared_ptr<PhysicsComponentBase> physicsComponent;
    DeathZone(float radius, Physics &physics) {
        PhysicsComponentBase(physics);
        
    }

};

#endif