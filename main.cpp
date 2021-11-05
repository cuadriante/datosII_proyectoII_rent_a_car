#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "Path.cpp"
#include "Graph.cpp"
#include "Edge.cpp"
#include "Button.h"
#include "Edge.h"
#include "Textbox.h"

using namespace std;
using namespace sf;

RenderWindow window;

Font font;
Text titleText;
Textbox vertexInput(25, sf::Color::White, false);

typedef struct path path_t;

struct path{
    int max_gas;
    int length;
    int path[0];

};

float frameWidth = 800;
float frameHeight = 800;

int pos1;
int pos2;

bool Choosing1 = false;
bool Choosing2 = false;
bool Finished = false;

int vertex;
int **adj;

Clock gameClock;
float deltaTime;

#include <vector>
#include <cstdlib>

RectangleShape background;
Texture textureBack;

Vertex Line;

vector<Button*> nodes;
vector<Edge*> edges;


void Update();
void Render();
void Initiate();
void HandleInput();
void loadMap(int pos1, int pos2);
void createGraph(int vertex);
void addedge(int vertex);
void backTracking();
void printGraph(int vertex);


int main() {
    sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - 445,
                              (sf::VideoMode::getDesktopMode().height / 2) - 480);
    //window.create(sf::VideoMode(800,800), "Rent-a-Car", sf::Style::Titlebar | sf::Style::Close);
    sf::RenderWindow window(sf::VideoMode(frameWidth, frameHeight), "Rent-a-car");
    window.setPosition(centerWindow);
    //window.setPosition(sf::Vector2i(500, 200));
    window.setKeyRepeatEnabled(true);
    Initiate();
    //Render();
    font.loadFromFile("consola.ttf");
    vertexInput.setFont(font);
    vertexInput.setPosition({100, 100});
    loadMap(pos1, pos2);
    while (window.isOpen()) {
        sf::Event Event;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            vertexInput.setSelected(true);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            vertexInput.setSelected(false);

        }
        while (window.pollEvent(Event)) {
            switch (Event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::TextEntered:
                    vertexInput.typedOn(Event);
            }
        }
        window.clear(Color::Black);
        vertexInput.setLimit(true,2);
        vertexInput.drawTo(window);
        window.display();
        deltaTime = gameClock.restart().asSeconds();
        //sf::CircleShape Circle(5,30);
        //Circle.setFillColor(sf::Color::Black);
        //window.draw(Circle);
        //loadMap(pos1, pos2);
        //userInput = to_string(xMousePos);
        if (Choosing1 && !Choosing2 && !Finished) {
            Update();
        }
        Render();

    }
    return EXIT_SUCCESS;

}
void Initiate() {
    font.loadFromFile("consola.ttf");

    //textureBall.loadFromFile("ball.png");
    //textureBack.loadFromFile("back.png");
    //texturePaddle.loadFromFile("paddle.png");
    //textureBrick.loadFromFile("brick.png");

    background.setSize(sf::Vector2f(800, 800));
    background.setPosition(0, 0);
    background.setTexture(&textureBack);

    titleText.setFont(font);
    titleText.setCharacterSize(100);
    titleText.setPosition(620, frameHeight-30);
    titleText.setString("Rent-a-Car");

    //gameOverText.setFont(font);
    //gameOverText.setCharacterSize(35);
    //gameOverText.setPosition(100, 400);
    //gameOverText.setString("");

    //scoreText.setFont(font);
    //scoreText.setCharacterSize(20);
    //scoreText.setPosition(80, frameHeight - 30);
    //scoreText.setString("score:"+ std::to_string(score));
}
void Reset(){
    Choosing1 = false;
    Choosing2 = false;
    Finished = false;
    //matriz [0][0] o clear()
    loadMap(pos1, pos2);

}


void Update(){
    loadMap(pos1, pos2);
    if (Finished){
        Reset();
    }
    if (Choosing1 && Choosing2){
        //llame a la matriz
        //metodo de backtracking
        loadMap(pos1, pos2);
        Finished = true;
    }


}
void Render() {
    window.clear(sf::Color::Black);
    window.draw(background);
    //window.draw(Line,sf::Lines);
  // window.draw(edge);
    window.display();
}
void loadMap(int pos1, int pos2) {
    //Graph(10);
    //int cityCount = getText();
    createGraph(10);
    addedge(10);
    printGraph(10);
    sf::Vertex Line[] =
            {
                    sf::Vertex(sf::Vector2f(50, 50)),
                    sf::Vertex(sf::Vector2f(100, 300))
            };
    window.draw(Line, 2, sf::Lines);
    //setVect(vector<vector<int>> pos1);
    //setVect(vector<vector<int>> pos2);
    //path_t *rec(path_t *path, Graph roads, int current, int start, int end, int n_routes);

    //backTracking();
    //for (int i = 0; i < ; ++i) {

    //}
    //vector<int>->addedge(5);
    //for (int i = 0; i < 5; ++i) {
//    sf::CircleShape button[] =
//            {
//                    sf::CircleShape(20, 30)
//            };
//    window.draw(button, 1, RenderStates::Default, sf::CircleShape);
    //for (int i = 0; i < 5; ++i) {
    //for (int j = 0; j < 5; ++i) {
//        sf::Vertex Line[] =
//                    {
//                            sf::Vertex(sf::Vector2f(500, 300)),
//                            sf::Vertex(sf::Vector2f(550, 400))
//
//                    };
//            window.draw(Line, 2, sf::Lines);
//            window.display();
//        }



    //agregar edge
    //sf::Vertex line = edge.createEdge(400,3,1);
    //window.draw();

//   Graph(5);
//   Edge *eptr = new Edge;
//   edges.push_back(eptr);
//   Node *nptr = new Node();
//   nodes.push_back(nptr);
}
void createGraph(int vertex){
        //this -> vertex = vertex;
        adj = new int*[vertex];

        for (int r = 0; r<vertex; r++){
            adj[r] = new int [vertex];
            for (int c = 0; c < vertex; c++){
                adj[r][c] = -1;
                cout<<adj[r][c]<<endl;
            }
        }
    }
void addedge(int vertex){
    int temp = vertex;
    int ale = rand() % (vertex * vertex);
    for (int k = 0; k < ale; ++k) {
        int gas = rand() % 50;
        int i = rand() % temp;
        int j = rand() % temp;
        if (adj[i][j] == -1 && i != j){
            adj[i][j] = gas;
            adj[j][i] = gas;
            cout<<gas<<endl;
            cout<< adj[i][j] << endl;
            cout<< adj[j][i] << endl;
        }
    }
}


//path_t *allocatePath(int n_routes) {
//    path_t *path = NULL;
//        path = (path_t *) malloc(sizeof(path_t) + n_routes * sizeof(path->path[0]));
//        if (path == NULL)
//            return NULL;
//
//        return path;
//    }
//    path_t *rec(path_t *path, Graph roads, int current, int start, int end, int n_routes) {
//        path_t *best_path, *cur_path;
//        int cur_best_gas, gas, path_length;
//
//
//        // If we've reached the end, return path
//        if (current == end)
//            return path;
//
//        best_path = allocatePath(n_routes);
//        best_path->max_gas = 1000;
//        for (int j = 0; j < n_routes; j++) {
//            best_path->path[j] = path->path[j];
//        }
//
//        // Save path length
//        path_length = path->length;
//
//        // Check every path
//        for (int i = 0; i < n_routes; i++) {
//            if (roads.adj[current][i] == -1 || i == start) // Non-existant paths
//                continue;
//
//            if (roads.adj[current][i] > path->max_gas)
//                path->max_gas = roads.adj[current][i];
//
//            // Set path location length to i
//            path->path[path_length] = i;
//            path->length = path_length + 1;
//
//            // Mark next location to your current one as -1, so you don't go back
//            roads.adj[i][current] = -1;
//
//            path = rec(path, roads, i, start, end, n_routes);
//
//            if (path->max_gas < best_path->max_gas) {
//                // Set best paths max gas to returned paths max gas
//                best_path->max_gas = path->max_gas;
//                best_path->length = path->length;
//
//                // Copy over path
//                for (int j = 0; j < n_routes; j++) {
//                    best_path->path[j] = path->path[j];
//                }
//            }
//        }
//
//        free(path);
//        return best_path;
//
//
//        printf("Best path, length -> %d\n", path->max_gas);
//        for (int i = 0; i < path->length; i++) {
//            printf("%d ", path->path[i]);
//        }
//        printf("\n");
//
//        return 0;
//    };

void printGraph(int vertex){
    for (int i = 0; i < vertex; i++){
            for (int j = 0; j < vertex; j++){
               cout<<adj[i][j]<<" ";
            }
           cout<<endl;
        }
    }
void setVect(vector<vector<int>> vect){
        for (int i = 0; i<vect.size(); i++){
            for (int j = 0; j <vect[i].size(); j++){
                adj[i][j] = vect[i][j];
            }
        }
    }