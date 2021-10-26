
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
};

typedef struct path path_t;
struct path {
    int max_gas;
    int length;
    int path[0];
};