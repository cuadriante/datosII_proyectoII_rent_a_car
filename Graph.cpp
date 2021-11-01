#include <iostream>
#include <vector>
#include "Graph.h"


using namespace std;


void Graph::addedge(int i, int j, int gas){
        if (adj[i][j] == -1){
            adj[i][j] = gas;
            adj[j][i] = gas;
        }
    }

    void Graph::setVect(vector<vector<int>> vect){
        for (int i = 0; i<vect.size(); i++){
            for (int j = 0; j <vect[i].size(); j++){
                adj[i][j] = vect[i][j];
            }
        }
    }

    vector<vector<int>> Graph::getVect(){
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
    void Graph::print(){
        for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }