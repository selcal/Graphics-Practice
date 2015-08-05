#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "manager.h"
///Include: Effects to be managed:
#include "flixel.h"
#include "follow.h"
///
using namespace sf;

manager::manager(){};

void manager::effect_update(int effect, RenderWindow& app, const float deltaTime)
{
    if(effect == 0)
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles[i].update(deltaTime);
        }
    }
}

void manager::effect_draw(int effect, RenderWindow& app)
{
    if(effect == 0)
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles[i].draw(app);
        }
    }
}

void manager::effect_start(int effect, const int a, const int b)
{
    if(effect == 0)
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles.push_back(pix(5.0, Vector2f(a / 2, b / 2)));
        }
    }
}

void manager::previous_effect(int& effect)
{
    //STUB
}

void manager::next_effect(int& effect)
{
    //STUB
}









