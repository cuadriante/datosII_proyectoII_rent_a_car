//
// Created by axel on 10/6/21.
//

#ifndef DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
#define DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
#include <SFML/Graphics.hpp>

class Graph {
public:
    struct adjNode {
        int val, cost;
        adjNode *next;
    };
    struct graphEdge {
        int start_ver, end_ver, weight;
    };
};


#endif //DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
