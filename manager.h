#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "flixel.h"
#include "follow.h"

using namespace sf;

class manager
{
public:
    manager();

    const int EFFECTS = 2;
    ///editable effect parameters:
    int particleCount = 500;
    int objectCount = 500;

    std::string get_effect_name(int effect); //GET effect's name.
    std::string get_effect_stats(int effect); //GET effect's statistics/info if any.

    void effect_update(int effect, RenderWindow& app, const float& deltaTime); //uses int effect to determine which effect it is to update
    void effect_draw(int effect, RenderWindow& app ); // same as above with drawing
    void effect_start(int effect, int a, int b); // a and b used for any values the effect needs to init.
    void effect_stop(int effect); // does anything needed to destroy the effect

    void previous_effect(int& effect); // <-
    void next_effect(int& effect); // ->

    void change_param(int& parameterToChange, int offsetValue); // quick changes to private params below

private:

    ///effect containers:
    std::vector<pix> particles; // used for flixel.h
    std::vector<follow> followers; // used for follow.h

};
