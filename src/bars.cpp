#include "bars.hpp"
#include <SFML/Graphics.hpp>


FunnyBars::FunnyBars(float w, float h) : barWidth(w), barHeight(h) {}

void FunnyBars::setPosition(float x, float y) {
    posX = x;
    posY = y;
}

bool FunnyBars::isCompleted() {
    return barWidth && barHeight && barsNum;
}

void FunnyBars::drawFunnyBars(sf::RenderWindow &window) {
    if (this->isCompleted()) {
        int barPosX = posX;

        for (int i = 0; i < barsNum - 1; i++) {
            sf::RectangleShape bar({barWidth, barHeight});
            bar.setFillColor(sf::Color::White);
            bar.setPosition({barPosX, posY});

            window.draw(bar);
            barPosX += 2 * barWidth;
        }

        totalLength = barPosX + barWidth - posX ;
    } else {
        std::cout << "The bars are not full" << std::endl;
    }
}