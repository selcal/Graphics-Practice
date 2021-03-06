#include "follow.h"

using namespace std;
using namespace sf;

follow::follow(const int& _speed, const Color& _color,const Vector2i& _position, const Vector2i& _previousPosition)
{
    speed = _speed;
    position = _position;
    previousPosition = _previousPosition;
    color = _color;
}

Vector2i follow::get_position()
{
    return position;
}

void follow::update(float const& deltaTime, RenderWindow& window)
{
    previousPosition = position;
    go_to_mouse(position,window);
}

void follow::draw(RenderWindow& window)
{
    window.draw(VA);
}
void follow::stop()
{
    VA.clear();
}

void follow::go_to_mouse(Vector2i& currentPosition, RenderWindow& window)
{
    currentPosition.x = currentPosition.x + (Mouse::getPosition().x - currentPosition.x);
    currentPosition.y = currentPosition.y + (Mouse::getPosition().y - currentPosition.y);
    VA.append(Vertex(sf::Vector2f(position),color));
}

bool follow::on_mouse(Vector2i& currentPosition, RenderWindow& window)
{
    if(currentPosition == Mouse::getPosition(window))
        return true;

    return false;
}




