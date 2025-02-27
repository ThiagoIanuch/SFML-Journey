#include <SFML/Graphics.hpp>
#include <iostream>

// Window properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int FRAMERATE_LIMIT = 60;

// Circles properties
const int NUMBER_OF_CIRCLES = 30;

void generateCircles();

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "03 - Pseudo random circle collisions");

    sf::Vector2f movement[50];


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.display();
    }
    return 0;
}

void generateCircles() {
    sf::CircleShape circles[NUMBER_OF_CIRCLES];

    window.setFramerateLimit(FRAMERATE_LIMIT);

    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_CIRCLES; i++)
    {
        movement[i] = sf::Vector2f(5, 5);
        circles[i].setRadius(rand() % 6 + 15);
        circles[i].setPosition(rand() % 800, rand() % 600);
        circles[i].setFillColor(sf::Color::Blue);
    }
}

void drawCircles() {
    for (auto c : circles)
    {
        window.draw(c);
    }
}

void detectCollision() {

    for (int i = 0; i < NUMBER_OF_CIRCLES; i++)
    {
        circles[i].move(movement[i]);

        if (circles[i].getPosition().x > 800 || circles[i].getPosition().x < 0)
        {
            movement[i].x = -movement[i].x;
        }
        else if (circles[i].getPosition().y > 600 || circles[i].getPosition().y < 0) {
            movement[i].y = -movement[i].y;
        }
    }
}