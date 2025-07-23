#include <SFML/Graphics.hpp>
#include "bars.hpp"

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::View view({500, 500}, {800, 800});
    window.setView(view);

    //amount of bars
    int n = 21;

    FunnyBars theBars;

    theBars.barsNum = n;
    theBars.barWidth = 15;
    theBars.setPosition(100, 100);

   
    float* testHeights = new float[n];

    for (int i = 0; i < n; i++){
        testHeights[i] = 200 - i * 20;
    }
    theBars.setBarHeights(testHeights, n);
    
    theBars.frameMargin = 10;
    theBars.frameThickness = 3;

    
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // update the view to the new size of the window
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }
        

        // clear the window with black color
        window.clear(sf::Color::Black);

        theBars.drawBars(window);
        //theBars.drawFrame(window);

        window.display();
    }
}           