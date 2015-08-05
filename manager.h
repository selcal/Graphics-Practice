#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "flixel.h"
#include "follow.h"

using namespace sf;

class manager
{
public:
    manager();

    std::string get_effect_name(); //GET effect's name.
    std::string get_effect_stats(); //GET effect's statistics/info if any.

    void effect_update(int effect, RenderWindow& app, const float deltaTime); //uses int effect to determine which effect it is to update
    void effect_draw(int effect, RenderWindow& app ); // same as above with drawing
    void effect_start(int effect, const int a, const int b);

    void previous_effect(int& effect);
    void next_effect(int& effect);

    int change_param(int parameterToChange);

private:
    const int EFFECTS = 1; // previous effect and next effect use (EFFECTS - 1) to actually get the num

    std::string effectName; //what is the name of the effect?
    std::string effectStats;

    ///editable effect parameters:
    int particleCount = 500;
    int objectCount = 500;
    ///effect containers:
    std::vector<pix> particles; // used for flixel.h
};
