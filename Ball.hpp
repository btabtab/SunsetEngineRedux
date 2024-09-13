#pragma once

#include <iostream>

#include "SunsetCore/Entity.hpp"
#include "SunsetCore/Rendering/RenderObject.hpp"
#include "SunsetCore/Rendering/RenderPoint.hpp"
class Ball : public SunsetEngine::Entity
{
private:
    int bounce_count;
public:
    Ball()
    {
        render_object = new SunsetEngine::RenderPoint(250, 250, SunsetEngine::Colour(230, 230, 100, 255));
        setMass(10);
        setGravityUse(true);
        setBounceStrength(0.5);
    }
    void behaviour(){ std::cout << "I am a ball\n"; }
};