#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "02 - Pseudo Random Circles");

	sf::CircleShape circle[50];

	for (int i = 0; i < 50; i++) {
		circle[i].setRadius(rand());
		circle[i].setPosition(500, 500);
		std::cout << i << " " << circle[i].getRadius() << std::endl;
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		for (int i = 0; i < 50; i++) {
			window.draw(circle[0]);
		}

		window.display();
	}

	return 0;
}