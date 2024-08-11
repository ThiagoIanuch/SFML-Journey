#include <SFML/Graphics.hpp>
#include <iostream>

// Váriaveis com informações da tela
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Criar o quadrado
sf::RectangleShape createSquare() {
    sf::RectangleShape square;

    square.setSize(sf::Vector2f(100, 100));

    square.setFillColor(sf::Color::Cyan);

    return square;
}

// Movimentar o quadrado
void handleMovement(sf::RectangleShape &squarePos) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && squarePos.getPosition().y > 0) {
        squarePos.move(sf::Vector2f(0.0, -0.25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && squarePos.getPosition().y + squarePos.getGlobalBounds().height < WINDOW_HEIGHT) {
        squarePos.move(sf::Vector2f(0.0, 0.25));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && squarePos.getPosition().x > 0) {
        squarePos.move(sf::Vector2f(-0.25, 0.0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && squarePos.getPosition().x + squarePos.getGlobalBounds().width < WINDOW_WIDTH) {
        squarePos.move(sf::Vector2f(0.25, 0.0));
    }
}

// Criar o triângulo
sf::ConvexShape createTriangle() {
    sf::ConvexShape triangle;

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0, 0));
    triangle.setPoint(1, sf::Vector2f(50, -100));
    triangle.setPoint(2, sf::Vector2f(100, 0));

    triangle.setPosition(350, 200);
    triangle.setFillColor(sf::Color::Magenta);

    return triangle;
}

// Criar o círculo
sf::CircleShape createCircle() {
    sf::CircleShape circle;

    circle.setRadius(50);

    circle.setPosition(sf::Vector2f(350, 350));
    circle.setFillColor(sf::Color::Blue);


    return circle;
}

int main()
{   
    // Criar a tela
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "01 - Basic shapes");

    // Chamar as formas geométricas
    sf::RectangleShape square = createSquare();
    sf::ConvexShape triangle = createTriangle();
    sf::CircleShape circle = createCircle();

    // Realizar os eventos na tela
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                //
            }
        }

        handleMovement(square);

        window.clear();
        window.draw(square);
        window.draw(triangle);
        window.draw(circle);
        window.display();
    }

    return 0;
}