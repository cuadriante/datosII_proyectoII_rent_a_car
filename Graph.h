////
//// Created by axel on 11/1/21.
////
//
<<<<<<< HEAD
//#pragma once
//#ifndef DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
//#define DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
//using namespace std;
//
//class Graph{
//public:
//    int vertex;
//    int **adj;
//
//    Graph(int vertex){
//        this -> vertex = vertex;
//        adj = new int*[vertex];
//
//    for (int r = 0; r<vertex; r++){
//        adj[r] = new int [vertex];
//        for (int c = 0; c < vertex; c++){
//            adj[r][c] = -1;
//        }
//    }
//}
//    void addedge(int i, int j, int gas);
//
//    void setVect(vector<vector<int>> vect);
//
//    vector<vector<int>> getVect();
//
//    void print();
//
//
//#endif //DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
=======
// Created by axel on 11/1/21.
//

#pragma once
#ifndef DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
#define DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
using namespace std;

class Graph{
int vertex;
    int **adj;

    public:
        Graph(int vertex){
            this -> vertex = vertex;
            adj = new int*[vertex];

            for (int r = 0; r<vertex; r++){
                adj[r] = new int [vertex];
                for (int c = 0; c < vertex; c++){
                    adj[r][c] = -1;
                }
            }
        }

    void addedge(int x, int y, int gas){
    }
    
    void setVect(vector<vector<int>> vect){
    }

    vector<vector<int>> getVect(){
    }

    void print(){
    }

}
#endif //DATOSII_PROYECTOII_RENT_A_CAR_GRAPH_H
>>>>>>> master
