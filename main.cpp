#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "GrafoClase.cpp"
using namespace std;
using namespace sf;

RenderWindow window;

float frameWidth = 800;
float frameHeight = 800;

Clock gameClock;
float deltaTime;

#include <vector>
#include <cstdlib>
CircleShape Node;
CircleShape background;
Texture textureBack;

void Initiate();
void Render();
void HandleInput();
void loadMap();


int main() {
    //GrafoClase(Grafo());
    window.create(VideoMode(frameWidth, frameHeight), "Rent-a-car");
    window.setPosition(Vector2i(950,-200));
    Initiate();
    Render();

    while (window.isOpen()){
        deltaTime = gameClock.restart().asSeconds();
        //HandleInput();
        //userInput = to_string(xMousePos);
        }

        //if (playing&&!gameOver&&!win) {
            //Update();


        Render();

    }


void Initiate() {
    //font.loadFromFile("consola.ttf");

    //textureBall.loadFromFile("ball.png");
    //textureBack.loadFromFile("back.png");
    //texturePaddle.loadFromFile("paddle.png");
    //textureBrick.loadFromFile("brick.png");

    background.setSize(Vector2f(frameWidth, frameHeight));
    background.setPosition(0, 0);
    background.setTexture(&textureBack);

    //lifeText.setFont(font);
    //lifeText.setCharacterSize(20);
    //lifeText.setPosition(620, frameHeight-30);
    //lifeText.setString("life:"+ std::to_string(life));

    //gameOverText.setFont(font);
    //gameOverText.setCharacterSize(35);
    //gameOverText.setPosition(100, 400);
    //gameOverText.setString("");

    //scoreText.setFont(font);
    //scoreText.setCharacterSize(20);
    //scoreText.setPosition(80, frameHeight - 30);
    //scoreText.setString("score:"+ std::to_string(score));
}
void Reset(){}

void Render() {
    window.clear(sf::Color::Black);
    //window.draw(background);
    window.display();
}
