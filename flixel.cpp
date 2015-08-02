#include "flixel.h"
#include <cmath> //rngesus
#include <ctime>

using namespace sf;

pix::pix(float const& _speed, Vector2f const& _position)
{
    srand(time(NULL));

    speed = _speed;
    position = _position;

    direction.x = 0.0;
    direction.y = speed * -1;
    // We are changing the direction to go up.

    VA.setPrimitiveType(LinesStrip);
    color = Color(0, 169, 0, 12);
}

pix::pix(float const& _speed, Vector2f const& _position, Color const& _color)
{
    srand(time(NULL));

    speed = _speed;
    position = _position;

    direction.x = 0.0;
    direction.y = speed * -1;

    VA.setPrimitiveType(LinesStrip);
    color = _color;
}

Vector2f pix::get_position()
{
    return position;
}

Vector2f pix::get_direction()
{
    return direction;
}

void pix::update(float const& deltaTime)
{
    previousPosition = position;
    decide_to_turn();
    position = position + direction;

    VA.append(Vertex(position,color));
}

void pix::draw(RenderWindow &window)
{
    window.draw(VA); //draw the Vertex Array right now.
}

void pix::decide_to_turn()
{
    if((rand() % 3 + 1) == 1)
    {
        pix::turn_left();
    }
    else if((rand() % 3 + 1) == 2)
    {
        pix::turn_right();
    }

    //3 means the line will continue it's course.
}

void pix::turn_left()
{
    if(direction.x != 0)
    {
        direction.y = direction.x * -1;
        direction.x = 0;
    }
    else //direction is facing Y axis
    {
        direction.x = direction.y;
        direction.y = 0;
    }
}

void pix::turn_right()
{
    if(direction.y != 0)
    {
        direction.x = direction.y * -1;
        direction.y = 0;
    }
    else //direction is facing X axis
    {
        direction.y = direction.x;
        direction.x = 0;
    }
}



