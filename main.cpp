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

int effectDisplayed = 0; //Which effect is being displayed on screen?
std::string effectStats = "It is a mystery";

bool showTextHUD = true;

const int windowWidth = 800;
const int windowHeight = 600;

const int countOffset = 10; //how much you'd like to change the amount of objects in a scene by when pressing up or down during an effect.

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

    Text info("Left/Right - Change effect \n Up/Down - Change number of elements if possible\n Some effects are interactive! \n H - Hide this text overlay.\n C - Restart the effect. ",font,12);
    Text name("No name :O",font,10);
    name.setPosition(windowWidth/2,windowHeight - 32);
    Text stats("No stats for this effect.",font,12);
    stats.setPosition(windowWidth/4,windowHeight - 32);

    man.effect_start(effectDisplayed,windowWidth,windowHeight);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();

            if (event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Escape)
                {
                    app.close();
                }

                if(event.key.code == Keyboard::H)
                {
                    showTextHUD = !showTextHUD;
                }

                if(event.key.code == Keyboard::C)
                {
                    man.effect_stop(effectDisplayed);
                    std::cout << "Restarting " <<  man.get_effect_name(effectDisplayed) << "...WITH NO SURVIVORS.\n";
                    man.effect_start(effectDisplayed,windowWidth,windowHeight);
                }

                if(event.key.code == Keyboard::Left || event.key.code == Keyboard::A)
                {
                    man.effect_stop(effectDisplayed);
                    man.previous_effect(effectDisplayed);
                    man.effect_start(effectDisplayed,windowWidth,windowHeight);
                }

                if(event.key.code == Keyboard::Right || event.key.code == Keyboard::D)
                {
                    man.effect_stop(effectDisplayed);
                    man.next_effect(effectDisplayed);
                    man.effect_start(effectDisplayed,windowWidth,windowHeight);
                }
                if(event.key.code == Keyboard::Down || event.key.code == Keyboard::S)
                {
                    man.effect_stop(effectDisplayed);
                    man.change_param(man.particleCount, -10);
                    std::cout << "Particle Count:" << man.particleCount << "\n";
                    man.effect_start(effectDisplayed,windowWidth,windowHeight);
                }
                if(event.key.code == Keyboard::Up || event.key.code == Keyboard::W)
                {
                    man.effect_stop(effectDisplayed);
                    man.change_param(man.particleCount, 10);
                    std::cout << "Particle Count:" << man.particleCount << "\n";
                    man.effect_start(effectDisplayed,windowWidth,windowHeight);
                }
            }
        }

        man.effect_update(effectDisplayed,app,deltaTime);

        name.setString(man.get_effect_name(effectDisplayed));
        stats.setString(man.get_effect_stats(effectDisplayed));

        app.clear();

        man.effect_draw(effectDisplayed,app);

        if(showTextHUD == true)
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
