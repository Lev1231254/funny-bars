#include "bars.hpp"
#include <SFML/Graphics.hpp>




FunnyBars::FunnyBars() {}

void FunnyBars::setPosition(float x, float y) {
    tablePosX = x;
    tablePosY = y;
}


void FunnyBars::setBarHeights(float* heights, int len){

    if (len == barsNum){
        barsHeights = new float[len];

        for (int i = 0; i < len; i++){
            barsHeights[i] = heights[i];

            if (heights[i] > barMaxHeight) barMaxHeight = heights[i];
        }
    }
    else {
        std::cout << "Length of a given array and number of bars are not equal\n";
        errorReported = true;
    }

}



bool FunnyBars::isCompleted() {
    return barWidth && barMaxHeight && barsNum;
}


void FunnyBars::drawFunnyBars(sf::RenderWindow &window) {
    //if error was reported, it doesnt do anything. If wasn't, it works the same

    if (this->isCompleted() && !errorReported) {
        float barPosX = tablePosX;

        //set position and draw each bar
        for (int i = 0; i < barsNum; i++) {
            sf::RectangleShape bar({barWidth, barsHeights[i]});

            bar.setFillColor(sf::Color::White);
            bar.setPosition({barPosX, tablePosY + barMaxHeight - barsHeights[i]});

            window.draw(bar);
            barPosX += 2 * barWidth;
        }

        totalWidth = barPosX + barWidth - tablePosX ;
        std::cout << "Drew bars succesfully!\n";

    } else if (!errorReported){
        std::cout << "The bars are not ready\n";
        errorReported = true;
    }
}