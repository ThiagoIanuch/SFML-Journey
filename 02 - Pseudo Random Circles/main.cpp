#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "02 - Pseudo Random Circles");

	sf::CircleShape circleShape;
	std::vector<sf::CircleShape> circles;
	sf::Clock clock;

	srand(time(NULL)); // Semente para gerar os circulos de forma pseudo aleatória

	while (window.isOpen()) {
		// Fechar a janela
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
				
		// Gerar os círculos
		if(clock.getElapsedTime().asMicroseconds() > 5) {
			circles.push_back(circleShape);

			circles.back().setRadius(rand() % 25 + 15);
			circles.back().setPosition(rand() % 800, rand() % 600);
			circles.back().setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));

			std::cout << "Circle " << circles.size() << ": Radius " << circles.back().getRadius() << "     Pos (X, Y) " << circles.back().getPosition().x << ", " << circles.back().getPosition().y << std::endl;

			clock.restart();
		}

		// Limpar
		window.clear();

		// Desenhar os círculos na tela
		for (int i = 0; i < circles.size(); i++) {
			window.draw(circles[i]);
		}

		window.display();
	}

	return 0;
}