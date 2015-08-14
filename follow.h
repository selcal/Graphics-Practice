#pragma once

#include <cmath>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class follow
{
public:
    follow(const int& _speed, const Color& _color, const Vector2i& _position, const Vector2i& _previousPosition);

    Vector2i get_position();

    void update(float const& deltaTime, RenderWindow& window);
    void draw(RenderWindow& window);

    void go_to_mouse(Vector2i& currentPosition, RenderWindow& window);
    bool on_mouse(Vector2i& currentPosition, RenderWindow& window);

private:
    int speed;
    Vector2i position;
    Vector2i previousPosition;
    Vertex* previousVertex; // used for deleting stale vertices.
    Color color;

    VertexArray VA;
};
