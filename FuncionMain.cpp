#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "grafo.h"
#include "backtracking.h"

using namespace std;


int main(int argc, char **argv) {
    path_t *path;
    int start, end, vert;

    path = allocatePath(5);
    path->length = 0;
    path->max_gas = 0;

    start = 0; // starting location
    end = 3; // end location
    vert = 5; // amount of cities

    Graph roads (5);

    //these will be randomised in a for() loop
    roads.addedge(0,1,15);
    roads.addedge(0,3,35);
    roads.addedge(1,2,20);
    roads.addedge(2,4,23);
    roads.addedge(2,3,17);
    roads.print();

    /* int roads[5][5] = { \
        -1,  15,  -1,  35,  -1, 
        15,  -1,  20,  -1,  -1, 
        -1,  20,  -1,  17,  23, 
        35,  -1,  17,  -1,  -1, 
        -1,  -1,  23,  -1,  -1
    }; */

    path = rec(path, roads, start, start, end, 5);
    
    printf("Best path, length -> %d\n", path->max_gas);
    for (int i = 0; i < path->length; i++) {
        printf("%d ", path->path[i]);
    }
    printf("\n");

    return 0;
}