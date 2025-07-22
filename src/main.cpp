#include <SFML/Graphics.hpp>
#include "bars.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    FunnyBars theBars(10, 100);
    theBars.setPosition(300, 300);
    theBars.barsNum = 100;
    


    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        theBars.drawFunnyBars(window);

        window.display();
    }
}           