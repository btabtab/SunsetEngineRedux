#pragma once

namespace SunsetEngine
{
    class RenderObject
    {
    private:
    public:
        RenderObject(){ /* Does nothing. */ }
        virtual void render() = 0;
    };
};