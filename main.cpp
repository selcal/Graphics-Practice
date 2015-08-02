    ///External:  ///
#include <SFML/Graphics.hpp>
    ///Standard: ///
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
    /// Effects: ///
#include "flixel.h"

///globals
using namespace sf;

const int windowWidth = 600;
const int windowHeight = 600;
int flixelCount = 420;

bool fullscreen;
std::fstream file;

int main()
{
    /*Options File Parsing*/

    srand(time(NULL));

    RenderWindow app(VideoMode(windowWidth,windowHeight), "Graphics Practice");
    app.setFramerateLimit(60);

    Clock dt;
    float deltaTime = 1.0;

    vector<pix> flixels;

    int positionX = windowWidth / 2;
    int positionY = windowHeight / 2;

    for(int i = 0; i < flixelCount; i++)
    {
        flixels.push_back(pix(2.0, Vector2f(positionX,positionY)));
        //create vector of flixel objects.
    }

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        ///refresh cycle
        for(int i = 0; i < flixelCount; i++)
        {
            flixels[i].update(deltaTime);
        }

        app.clear();

        for(int i = 0; i < flixelCount; i++)
        {
            flixels[i].draw(app);
        }

        app.display();
        ///
        deltaTime = dt.restart().asSeconds();
    }

    return EXIT_SUCCESS;
}
