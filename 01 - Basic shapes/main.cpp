#include <SFML/Graphics.hpp>
#include <iostream>

// Window properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Set square properties
sf::RectangleShape createSquare() 
{
    sf::RectangleShape square;

    square.setSize(sf::Vector2f(100, 100));

    square.setFillColor(sf::Color::Cyan);

    square.setPosition(50, 50);

    return square;
}

// Detect square collisions with circle or triangle
bool detectCollision(sf::RectangleShape &square, sf::ConvexShape triangle, sf::CircleShape circle) 
{
    if (square.getGlobalBounds().intersects(triangle.getGlobalBounds()) || square.getGlobalBounds().intersects(circle.getGlobalBounds()))
    {
        std::cout << "Object collision: true" << std::endl;

        return true;
    }

    std::cout << "Object collision: false" << std::endl;

    return false;
}

// Move the square
void handleMovement(sf::RectangleShape &square, sf::ConvexShape triangle, sf::CircleShape circle) 
{
    square.setOrigin(50.f, 50.f);

    sf::Vector2f movement(0.0f, 0.0f);
    float rotation = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && square.getPosition().y - 50 > 0)
    {
        movement = sf::Vector2f(0.0f, -0.25f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && square.getPosition().y + square.getGlobalBounds().height < WINDOW_HEIGHT + 50)
    {
        movement = sf::Vector2f(0.0f, 0.25f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && square.getPosition().x - 50 > 0)
    {
        movement = sf::Vector2f(-0.25f, 0.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && square.getPosition().x + square.getGlobalBounds().width < WINDOW_WIDTH + 50)
    {
        movement = sf::Vector2f(0.25f, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) 
    {
        rotation = 0.05f;
    }

    sf::Vector2f originalPos = square.getPosition();
    float originalRotation = square.getRotation();

    square.move(movement);
    square.rotate(rotation);

    if (detectCollision(square, triangle, circle)) 
    {
        square.setPosition(originalPos);
        square.setRotation(originalRotation);
    }
}

// Set triangle properties
sf::ConvexShape createTriangle() 
{
    sf::ConvexShape triangle;

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(50, -100));
    triangle.setPoint(2, sf::Vector2f(100, 0));

    triangle.setPosition(350, 200);
    triangle.setFillColor(sf::Color::Magenta);

    return triangle;
}

// Set circle properties
sf::CircleShape createCircle() 
{
    sf::CircleShape circle;

    circle.setRadius(50);

    circle.setPosition(sf::Vector2f(350, 350));
    circle.setFillColor(sf::Color::Blue);


    return circle;
}

int main()
{   
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "01 - Basic shapes");

    sf::RectangleShape square = createSquare();
    sf::ConvexShape triangle = createTriangle();
    sf::CircleShape circle = createCircle();

    sf::Clock clock;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }
        }

        sf::Time time = clock.getElapsedTime();
        std::cout << "FPS: " << static_cast < int>(1.0f / time.asSeconds()) << "    ";
        clock.restart();

        handleMovement(square, triangle, circle);

        window.clear();
        window.draw(square);
        window.draw(triangle);
        window.draw(circle);
        window.display();
    }

    return 0;
}