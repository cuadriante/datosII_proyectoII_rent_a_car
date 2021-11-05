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
    Button() {}
    /**
     * @brief Constructor de función para botón
     * @param t texto a mostrar en el botón
     * @param charSize tamaño del bontón
     * @param bgColor color del botón
     * @param textColor color del texto del botón
     */
    Button(std::string t, int charSize, sf::Color bgColor, sf::Color textColor) {
        text.setString(t);
        text.setColor(textColor);
        text.setCharacterSize(charSize);
        button.setPointCount(30);
        button.setRadius(30);
        button.setFillColor(bgColor);

    }
/**
 * @brief define el tipo de fuente para el texto del botón
 * @param font tipo de fuente de texto
 */
    void setFont(sf::Font &font) {
        text.setFont(font);
    }
/**
 *@brief setea el color del fondo del boton
 *@param color
 */
    void setBackColor(sf::Color color) {
        button.setFillColor(color);
    }
/**
 * @brief setea el color del texto
 * @param color
 */
    void setTextColor(sf::Color color) {
        text.setColor(color);
    }
/**
 * @brief Setea la posicion del boton en la pantalla
 * @param pos
 */
    void setPosition(sf::Vector2f pos) {
        button.setPosition(pos);
        float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
        float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
        text.setPosition({xPos, yPos});
    }
/**
 * @brief Dibuja el boton en la pantalla
 * @param window
 */
    void drawTo(sf::RenderWindow &window) {
        window.draw(button);
        window.draw(text);
    }
/**
 *@brief Revisa cuando la posición de mouse esta encima del boton
 * @param window
 * @return
 */
    bool isMouseOver(sf::RenderWindow &window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }

private:
    sf::CircleShape button;
    sf::Text text;
    String id;
};


#endif //DATOSII_PROYECTOII_RENT_A_CAR_BUTTON_H
