//
// Created by axel on 11/4/21.
//

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox{
public:
    /**
     * @brief Constructor para clase Textbox
     * @param Size
     * @param color
     * @param sel
     */
    Textbox(int Size, sf::Color color, bool sel){
        textbox.setCharacterSize(Size);
        textbox.setColor(color);
        isSelected=false;
        textbox.setString("Digitar cantidad de ciudades (entre 1-10)");

    }
    /**
     * @brief Setea el font al textbox
     * @param font
     */
    void setFont(sf::Font &font){
        textbox.setFont(font);
    }
    /**
     * @brief setea la posicion del textbox
     */
    void setPosition(sf::Vector2f pos){
        textbox.setPosition(pos);
    }
    /**
     * @brief setea un limit de caracteres
     * @param ToF
     */
    void setLimit(bool ToF){
        hasLimit = ToF;
    }
    /**
     * @brief setea un limite de caracteres
     * @param ToF
     * @param lim
     */
    void setLimit(bool ToF, int lim){
        hasLimit = ToF;
        limit = lim-1;
    }
    /**
     * @brief setea como seleccionado el textbox
     * @param sel
     */
    void setSelected(bool sel){
        isSelected = sel;
        if(!sel){
            std::string t = text.str();
            std::string newT = "";
            for(int i = 0; i < t.length(); i++){
                newT += t[i];
        }
            textbox.setString(newT);
    }
    }
    std::string getText(){
        return text.str();
    }
    /**
     * @brief Dibuja el textBox a la ventana
     * @param window
     */
    void drawTo(sf::RenderWindow &window){
        //window.draw(background);
        window.draw(textbox);
    }
    /**
     * @brief Metodo para escribir caracteres en el textbox
     * @param input
     */
    void typedOn(sf::Event input){
        if(isSelected){
            int charTyped = input.text.unicode;
            if(charTyped <128){
                if(hasLimit){
                    if(text.str().length()<= limit){
                    inputLogic(charTyped);
                }
                else if(text.str().length()> limit && charTyped == DELETE_KEY){
                    deleteLastChar();
                }
            }
            else{
                inputLogic(charTyped);
            }}
        }
    }

private:
    RectangleShape background;
    sf::Text textbox;
    std::ostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;
    //string inputCity;
    /**
     * @brief Hace input a la logica de caracteres
     * @param charTyped
     */
    void inputLogic(int charTyped){
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY){
        text << static_cast<char>(charTyped);
        }
        else if(charTyped == DELETE_KEY){
            if(text.str().length()>0){
               deleteLastChar();
            }
        }
        textbox.setString(text.str() + "_");
    }
    /**
     * @brief metodo de delete, borra un caracter
     */
    void deleteLastChar() {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;

        textbox.setString(text.str());
    }
};

