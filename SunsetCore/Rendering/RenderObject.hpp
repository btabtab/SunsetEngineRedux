#pragma once

#include "Colour.hpp"

namespace SunsetEngine
{
    class RenderObject
    {
    private:
    protected:
    public:
        RenderObject(){ /* Does nothing. */ }
        virtual void render() = 0;
        virtual ~RenderObject() = default;
    };
};