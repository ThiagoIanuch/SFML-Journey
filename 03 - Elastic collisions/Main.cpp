#include <SFML/Graphics.hpp>
#include <iostream>

// Window properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int FRAMERATE_LIMIT = 60;

// Circles properties
const int NUMBER_OF_CIRCLES = 30;

void generateCircles(sf::RenderWindow& window);
void drawCircles(sf::RenderWindow& window, std::vector<sf::CircleShape> circles);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "03 - Pseudo random circle collisions");

    window.setFramerateLimit(FRAMERATE_LIMIT);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        generateCircles(window);

        //window.clear();

        window.display();
    }
    return 0;
}

void generateCircles(sf::RenderWindow &window) {
    std::vector<sf::CircleShape> circles;

    srand(time(NULL));

    for (int i = 0; i < NUMBER_OF_CIRCLES; i++)
    {
        sf::CircleShape circle;

        circle.setRadius(rand() % 6 + 15); 
        circle.setPosition(rand() % 800, rand() % 600); 
        circle.setFillColor(sf::Color::Blue);

        circles.push_back(circle);
    }

    drawCircles(window, circles);
}

void drawCircles(sf::RenderWindow& window, std::vector<sf::CircleShape> circles) {
    for (auto c : circles)
    {
        window.draw(c);
    }
}

/*
        //movement[i] = sf::Vector2f(5, 5);
    // sf::Vector2f movement[50];
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
*/