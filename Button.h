//
// Created by axel on 10/26/21.
//

#ifndef DATOSII_PROYECTOII_RENT_A_CAR_BUTTON_H
#define DATOSII_PROYECTOII_RENT_A_CAR_BUTTON_H
#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Button {
public:
    Button(){}

    Button(std::string t, int charSize, sf::Color bgColor, sf::Color textColor) {
        text.setString(t);
        text.setColor(textColor);
        text.setCharacterSize(charSize);
        button.setPointCount(30);
        button.setRadius(30);
        button.setFillColor(bgColor);

    }
    void setFont(sf::Font &font){
        text.setFont(font);
    }
    void setBackColor(sf::Color color){
        button.setFillColor(color);
    }
    void setTextColor(sf::Color color){
        text.setColor(color);
    }
    void setPosition(sf::Vector2f pos){
        button.setPosition(pos);
        float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
        float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
        text.setPosition({xPos,yPos});
    }
    void drawTo(sf::RenderWindow &window){
        window.draw(button);
        window.draw(text);
    }
    bool isMouseOver(sf::RenderWindow &window){
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosWidth = button.getPosition().y + button.getLocalBounds().height;
    }
    //bool enable = true;


    //int nodeID;


    //void initiate();

    //void setSize();

    //void setPosition();

    //void setConexion();
private:
    sf::CircleShape button;
    sf::Text text;
    String id;
};


#endif //DATOSII_PROYECTOII_RENT_A_CAR_BUTTON_H
