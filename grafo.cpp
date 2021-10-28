#include <iostream>
#include <vector>
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
    
    void addedge(int i, int j, int gas){
        if (adj[i][j] == -1){
            adj[i][j] = gas;
            adj[j][i] = gas;
        }
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

};

typedef struct path path_t;
struct path {
    int max_gas;
    int length;
    int path[0];
};
