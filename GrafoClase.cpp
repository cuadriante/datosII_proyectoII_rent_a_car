#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

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
        adj[x][y] = gas;
        adj[y][x] = gas;
    }

    void print(){
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main(int argc, char **argv) {
    Graph test (5);
    test.addedge(0,1,15);
    test.addedge(0,3,35);
    test.addedge(1,2,20);
    test.addedge(2,4,23);
    test.addedge(2,3,17);
    test.print();
    
    /* int roads[5][5] = { \
        -1,  15,  -1,  35,  -1, 
        15,  -1,  20,  -1,  -1, 
        -1,  20,  -1,  17,  23, 
        35,  -1,  17,  -1,  -1, 
        -1,  -1,  23,  -1,  -1
    }; */

    return 0;
}