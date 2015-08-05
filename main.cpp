    ///External:  ///
#include <SFML/Graphics.hpp>
    ///Standard: ///
#include <iostream>
#include <fstream>
#include <ctime>

#include "manager.h" //'plays' certain effects and returns information about them.
/// Effects: ///

using namespace sf;

std::fstream file;

int effectDisplayed = 0;

bool showTextHUD = true;

const int windowWidth = 1366;
const int windowHeight = 768;

int main()
{
    manager man;

    /*Options File Parsing*/

    srand(time(NULL));

    RenderWindow app(VideoMode(windowWidth,windowHeight), "Graphics Practice");
    app.setFramerateLimit(60);

    Clock dt;
    float deltaTime = 1.0;

    Font font;
    if(!font.loadFromFile("font.ttf"))
        return EXIT_FAILURE;

    Text info(" Left/Right - Change effect \n Up/Down - Change number of elements if possible \n H - Hide this text.",font,12);
    Text name("Flixel",font,9);
    name.setPosition(windowWidth/2,windowHeight - 32);
    Text stats("No stats for this effect.",font,9);
    stats.setPosition(windowWidth/3,windowHeight - 32);

    man.effect_start(effectDisplayed,windowWidth,windowHeight);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();

            if(Keyboard::isKeyPressed(Keyboard::H))
            {
                showTextHUD = !showTextHUD;
            }

            if(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
            {
                man.previous_effect(effectDisplayed);
                man.effect_start(effectDisplayed,windowWidth,windowHeight);
            }

            if(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
            {
                man.next_effect(effectDisplayed);
                man.effect_start(effectDisplayed,windowWidth,windowHeight);
            }
        }

        man.effect_update(effectDisplayed,app,deltaTime);

        app.clear();

        man.effect_draw(effectDisplayed,app);

        if(showTextHUD)
        {
            app.draw(info);
            app.draw(name);
            app.draw(stats);
        }

        app.display();

        deltaTime = dt.restart().asSeconds(); //time
    }

    return EXIT_SUCCESS;
}
