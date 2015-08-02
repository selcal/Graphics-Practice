#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class pix
{
public:

    pix(float const& _speed, Vector2f const& _position); //OVERLOAD 1 SPEED POSITION
    pix(float const& _speed, Vector2f const& _position, Color const& _color); //OVERLOAD 2 SPEED POSITION COLOR

    Vector2f get_position();
    Vector2f get_direction();

    void turn_left(); //turns the line left due to decide to turns decision
    void turn_right(); // ^ above for right direction
    void decide_to_turn(); // uses CMATH RNG to determine whether to turn to the left or right, calls functions above inside this func

    void update(float const& deltaTime);
    void draw(RenderWindow &window);

private:

    float speed;

    Vector2f previousPosition;
    Vector2f position;
    Vector2f direction;
    Color color;

    VertexArray VA;
};

