//
// Created by axel on 10/26/21.
//

#ifndef DATOSII_PROYECTOII_RENT_A_CAR_NODE_H
#define DATOSII_PROYECTOII_RENT_A_CAR_NODE_H
#pragma once
#include <SFML/Graphics.hpp>

class Node {
public:

    bool enable = true;
    sf::CircleShape picture;

    int nodeID;


    void initiate();

    void setSize();

    void setPosition();

    void setConexion();

};


#endif //DATOSII_PROYECTOII_RENT_A_CAR_NODE_H
