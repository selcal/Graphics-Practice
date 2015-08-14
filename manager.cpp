#include "manager.h"
///Include: Effects to be managed:
#include "flixel.h"
#include "follow.h"
///
#include <string>
#include <iomanip>

using namespace sf;

manager::manager(){};

std::string manager::get_effect_name(int effect)
{
    switch(effect)
    {
        case 0:
        return "Flixels";
        case 1:
        return "MouseFollowers";
        default:
        return "Unknown Effect Name :(";
    }
}
std::string manager::get_effect_stats(int effect)
{
    switch(effect)
    {
        case 0:
        return "No information yet.";
        case 1:
        return "Try moving your mouse around!";
        default:
        return "Unknown Effect Name :(";
    }
}

void manager::effect_update(int effect, RenderWindow& app, const float& deltaTime)
{
    if(effect == 0) /// FLIXEL
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles[i].update(deltaTime);
        }
    }

    if(effect == 1) /// FOLLOW
    {
        for(int i = 0; i < particleCount; i++)
        {
            followers[i].update(deltaTime,app);
        }
    }
}

void manager::effect_draw(int effect, RenderWindow& app)
{
    if(effect == 0) ///FLIXEL
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles[i].draw(app);
        }
    }

    if(effect == 1) ///FOLLOW
    {
        for(int i = 0; i < particleCount; i++)
        {
            followers[i].draw(app);
        }
    }
}

void manager::effect_start(int effect, int a, int b)
{
    if(effect == 0) ///FLIXEL
    {
        for(int i = 0; i < particleCount; i++)
        {
            particles.push_back(pix(5.0, Vector2f(a / 2, b / 2)));
        }
    }

    if(effect == 1) ///FOLLOW
    {
        for(int i = 0; i < particleCount; i++)
        {
            followers.push_back(follow(3, Color::Red, Vector2i(a / 2, b / 2), Vector2i(a/2,b/2)));
        }
    }
}

void manager::effect_stop(int effect)
{
    //stub
}

void manager::previous_effect(int& effect)
{
    if(effect == 0)
    {
        effect = EFFECTS - 1;
    }
    else
    {
        effect--;
    }
}

void manager::next_effect(int& effect)
{
    if(effect == EFFECTS - 1) //wrap around because there are no more effects!
    {
        effect = 0;
    }
    else
    {
        effect++;
    }
}









