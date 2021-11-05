#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;


class Graph{
    public:
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
    
    void setVect(vector<vector<int>> vect){
        for (int i = 0; i<vect.size(); i++){
            for (int j = 0; j <vect[i].size(); j++){
                adj[i][j] = vect[i][j];
            }
        }
    }

    vector<vector<int>> getVect(){
        vector<vector<int>> vect;

        for (int i = 0; i < vertex; i++){
            vector<int> temp;
            for (int j = 0; j < vertex; j++){
                temp.push_back(adj[i][j]);
            }

            vect.push_back(temp);
        }

        return vect;
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


/* path_t *rec(path_t *path, Graph roads, int current, int start, int end, int n_routes) {
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
       if (roads.adj[current][i] == -1 || i == start) // Non-existant paths
           continue;

       if (roads.adj[current][i] > path->max_gas)
           path->max_gas = roads.adj[current][i];

       // Set path location length to i
       path->path[path_length] = i;
       path->length = path_length + 1;

       // Mark next location to your current one as -1, so you don't go back
       roads.adj[i][current] = -1;

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
} */

path_t *rec(path_t *path, vector<vector<int>> roads, int current, int start, int end, int n_routes) {
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


int main(int argc, char **argv) {
    path_t *path;

    int vert = rand () % 10;
    int start, end, i, j, gas;

    Graph roads (5);
    
    int rep = rand () % (vert * vert);
    
/*     for (int k = 0; k < rep; ++k){
    	gas = rand() % 50;
    	i = rand() % vert;
    	j = rand() % vert;
    	roads.addedge(i,j,gas);
    } */

    roads.addedge(0,1,15);
    roads.addedge(0,3,35);
    roads.addedge(1,2,20);
    roads.addedge(2,4,23);
    roads.addedge(2,3,17);
    
    roads.print();

    vector<vector<int>> roads1 = roads.getVect();
         
    cout<<"Enter your origin city: ";
    cin>>start;
    cout<<"Enter your destination city: ";
    cin>>end;
    
    path = rec(path, roads1, start, start, end, vert);
    
    cout<<"the best path between city "<<start<<" and city "<<end<<"is "<<path->max_gas;
    cout<<"this is the route taken by the algorithm: "<<endl;
    for (int w = 0; i < path->length; w++){
    	cout<<path->path[i]<<endl;
    }
    

    return 0;
}
