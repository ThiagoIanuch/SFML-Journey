#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "02 - Pseudo Random Circles");

	srand(time(NULL));
	sf::CircleShape circle[250];

	for (int i = 0; i < 250; i++) {
		circle[i].setRadius(rand() % 100);
		circle[i].setPosition(rand() % 1000, rand() % 1000);
		circle[i].setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		std::cout << i << " " << circle[i].getRadius() << std::endl;
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		for (int i = 0; i < 250; i++) {
			window.draw(circle[i]);
		}

		window.display();
	}

	return 0;
}