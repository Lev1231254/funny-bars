#include <SFML/Graphics.hpp>
#include "bars.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "THE FUNNY BARS");

    sf::View view({500, 500}, {800, 800});
    window.setView(view);

    int n = 21;  //amount of bars

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

        while (const std::optional event = window.pollEvent())
        {

            if (event->is<sf::Event::Closed>())
                window.close();
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
                window.setView(sf::View(visibleArea));
            }
        }
        

        window.clear(sf::Color::Black);

        theBars.drawBars(window);
        theBars.drawFrameDown(window);

        window.display();
    }
}           