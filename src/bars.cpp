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


void FunnyBars::drawBars(sf::RenderWindow &window) {
    //if error was reported, it doesnt do anything. If wasn't, it works the same

    if (this->isCompleted() && !errorReported) {
        //position of bars not including margin and thickness
        float trueBarsPosX = tablePosX + frameMargin + frameThickness;
        float trueBarsPosY = tablePosY + frameMargin + frameThickness;

        float barPosX = trueBarsPosX;

        //set position of and draw each bar
        for (int i = 0; i < barsNum; i++) {
            sf::RectangleShape bar({barWidth, barsHeights[i]});

            bar.setFillColor(sf::Color::White);
            bar.setPosition({barPosX, trueBarsPosY + barMaxHeight - barsHeights[i]});

            window.draw(bar);
            barPosX += 2 * barWidth;
        }

        //(-barWidth) accounting for additional cycle, when setting position of each bar
        barPosX -= barWidth;

        totalBarsWidth = barPosX - trueBarsPosX;

    } else if (!errorReported){
        std::cout << "The bars are not ready\n";
        errorReported = true;
    }
}


void FunnyBars::drawFrame(sf::RenderWindow &window){
    //draw up, down, left, right rectangles
    sf::RectangleShape rectUp({totalBarsWidth + 2 * (frameMargin + frameThickness), frameThickness});
    rectUp.setPosition({tablePosX, tablePosY});
    rectUp.setFillColor(sf::Color::White);


    sf::RectangleShape rectDown({totalBarsWidth + 2 * (frameMargin + frameThickness), frameThickness});
    rectDown.setPosition({tablePosX, tablePosY + frameThickness + 2 * frameMargin + barMaxHeight});
    rectDown.setFillColor(sf::Color::White);
    

    sf::RectangleShape rectLeft({frameThickness, barMaxHeight + 2 * (frameMargin + frameThickness)});
    rectLeft.setPosition({tablePosX, tablePosY});
    rectLeft.setFillColor(sf::Color::White);


    sf::RectangleShape rectRight({frameThickness, barMaxHeight + 2 * (frameMargin + frameThickness)});
    rectRight.setPosition({tablePosX + frameThickness + 2 * frameMargin + totalBarsWidth, tablePosY});
    rectRight.setFillColor(sf::Color::White);


    window.draw(rectUp);
    window.draw(rectDown);
    window.draw(rectLeft);
    window.draw(rectRight);
}