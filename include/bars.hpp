#ifndef BARS_H
#define BARS_H

#include <SFML/Graphics.hpp>
#include <iostream>

class FunnyBars {
public:
    float barWidth = 0; 
    float barHeight = 0;
    float posX = 0;
    float posY = 0;
    float barsNum = 0;
    float totalLength = 0;
    


    FunnyBars(float w, float h);

    void setPosition(float x, float y);

    bool isCompleted();


    void drawFunnyBars(sf::RenderWindow &window);

};
#endif