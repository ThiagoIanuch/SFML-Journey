#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{   
    sf::RenderWindow window(sf::VideoMode(800, 600), "01 - Basic shapes");

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color::Cyan);


    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPosition(400, 300);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(50, -100));
    triangle.setPoint(2, sf::Vector2f(100, 0));
    triangle.setFillColor(sf::Color::Magenta);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mover
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rectangle.move(sf::Vector2f(0.0, -0.25));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            rectangle.move(sf::Vector2f(0.0, 0.25));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            rectangle.move(sf::Vector2f(-0.25, 0.0));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            rectangle.move(sf::Vector2f(0.25, 0.0));
        }


        window.clear();
        window.draw(triangle);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}