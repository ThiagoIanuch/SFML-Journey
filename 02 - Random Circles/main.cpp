#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "02 - Random Circles");

	sf::CircleShape circle;
	circle.setRadius(50);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.draw(circle);

		window.display();
	}

	return 0;
}