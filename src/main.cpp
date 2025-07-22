#include <SFML/Graphics.hpp>
#include "bars.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");


    FunnyBars theBars;

    theBars.barsNum = 10;
    theBars.barWidth = 10;
    theBars.setPosition(100, 100);

    int n = 10;
    float* testHeights = new float[n];

    for (int i = 0; i < 10; i++){
        testHeights[i] = i * 20 + 20;
    }
    theBars.setBarHeights(testHeights, n);
    
    theBars.frameMargin = 10;
    theBars.frameThickness = 5;

    
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

        theBars.drawBars(window);
        theBars.drawFrame(window);

        window.display();
    }
}           