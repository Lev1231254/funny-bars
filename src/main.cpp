#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    sf::CircleShape greenCircle(50.f);
    greenCircle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape redRectangle({120, 50});
    redRectangle.setFillColor(sf::Color::Red);
    redRectangle.setPosition({300, 300});


    
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

        window.draw(greenCircle);
        window.draw(redRectangle);

        window.display();
    }
}           