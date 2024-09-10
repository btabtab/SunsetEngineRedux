#pragma once

namespace SunsetEngine
{
    class RenderObject
    {
    private:
        RenderObject(){ /* Does nothing. */ }
    public:
        virtual void render();
    };
};