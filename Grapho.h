//
// Created by axel on 11/3/21.
//

#ifndef DATOSII_PROYECTOII_RENT_A_CAR_GRAPHO_H
#define DATOSII_PROYECTOII_RENT_A_CAR_GRAPHO_H
class Graph {
    int vertex;

public:
    Graph(int vertex) {
        this->vertex = vertex;
        adj = new int *[vertex];

        for (int r = 0; r < vertex; r++) {
            adj[r] = new int[vertex];
            for (int c = 0; c < vertex; c++) {
                adj[r][c] = -1;
            }
        }
    };
    int **adj;
};

#endif //DATOSII_PROYECTOII_RENT_A_CAR_GRAPHO_H
