#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct path path_t;
struct path {
    int max_gas;
    int length;
    int path[0];
};


path_t *allocatePath(int n_routes) {
    path_t *path = NULL;
    path = (path_t *) malloc(sizeof(path_t) + n_routes * sizeof(path->path[0]));
    if (path == NULL)
        return NULL;

    return path;
}


path_t *rec(path_t *path, int roads[5][5], int current, int start, int end, int n_routes) {
    path_t *best_path, *cur_path;
    int cur_best_gas, gas, path_length;
    

    // If we've reached the end, return path
    if (current == end)
        return path;
        
    best_path = allocatePath(n_routes);
    best_path->max_gas = 1000;
    for (int j = 0; j < n_routes; j++) {
        best_path->path[j] = path->path[j];
    }

    // Save path length
    path_length = path->length;

    // Check every path
    for (int i = 0; i < n_routes; i++) {
        if (roads[current][i] == -1 || i == start) // Non-existant paths
            continue;

        if (roads[current][i] > path->max_gas)
            path->max_gas = roads[current][i];
        
        // Set path location length to i
        path->path[path_length] = i;
        path->length = path_length + 1;
        
        // Mark next location to your current one as -1, so you don't go back
        roads[i][current] = -1;

        path = rec(path, roads, i, start, end, n_routes);

        if (path->max_gas < best_path->max_gas) {
            // Set best paths max gas to returned paths max gas
            best_path->max_gas = path->max_gas;
            best_path->length = path->length;

            // Copy over path
            for (int j = 0; j < n_routes; j++) {
                best_path->path[j] = path->path[j];
            }
        }
    }

    free(path);
    return best_path;
}

int main(int argc, char *argv) {
    path_t *path;
    int start, end, vert, i, j;

    path = allocatePath(5);
    path->length = 0;
    path->max_gas = 0;
    
    start = 0; //starting location
    end = 3; //end location
    vert = 5; //amount of cities
    
//	int roads [vert]vert];
//	
//	for (i = 0; i<5; i++){
//		for (j = i; j<5; j++){
//			if (i!=j){
//				roads[i][j] = rand() % 50;
//				cout<<roads[i][j];
//				cout<<"\n\n";
//				roads[j][i] = roads[i][j];
//			}
//			else{
//				roads[i][j] = -1;
//			}
//		}
//	}
	
    int roads[5][5] = { \
       -1,  15,  -1,  35,  -1, 
       15,  -1,  20,  -1,  -1, 
        -1,  20,  -1,  17,  23, 
        35,  -1,  17,  -1,  -1, 
        -1,  -1,  23,  -1,  -1
    };

	cout<<"stop";

    path = rec(path, roads, start, start, end, vert);
    
    printf("Best path, length -> %d\n", path->max_gas);
    for (int i = 0; i < path->length; i++) {
        printf("%d ", path->path[i]);
    }
    printf("\n");
    
    return 0;
}
