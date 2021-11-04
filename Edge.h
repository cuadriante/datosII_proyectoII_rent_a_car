//
// Created by axel on 10/26/21.
//

#ifndef DATOSII_PROYECTOII_RENT_A_CAR_EDGE_H
#define DATOSII_PROYECTOII_RENT_A_CAR_EDGE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
using namespace sf;
using namespace std;

class Edge {
public:
    int pos1;
    int pos2;
    int idEdge;
    int weight;
    sf::RectangleShape edge;
    sf::Vertex createEdge(int pos1, int pos2, int idEdge);


    //void setPosition();

    //void setSize();


    //void getIdEdge();

    //sf::Vertex<int> setIdEdge(int idEdge);
};


#endif //DATOSII_PROYECTOII_RENT_A_CAR_EDGE_H
