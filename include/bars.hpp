#ifndef BARS_H
#define BARS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class FunnyBars {
private: 
    bool errorReported = 0;
public:
    float barWidth = 0; 
    float totalBarsWidth = 0;
    float barMaxHeight = 0;

    float tablePosX = 0;
    float tablePosY = 0;

    float barsNum = 0;
    float* barsHeights;

    float frameThickness = 0;
    float frameMargin = 0;

    
    FunnyBars();


    void setPosition(float x, float y);

    void setBarHeights(float* heights, int n);

    bool isCompleted();

    void drawBars(sf::RenderWindow &window);

    void drawFrame(sf::RenderWindow &window);

};
#endif