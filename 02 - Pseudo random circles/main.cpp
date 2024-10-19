#include <SFML/Graphics.hpp>
#include <iostream>

// Window properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// Generation properties
const float CIRCLE_GENERATION_INTERVAL = 0.001f;

// Circle properties
const int MIN_RADIUS = 20;
const int MAX_RADIUS = 30;

const int MIN_R_COLOR = 0;
const int MAX_R_COLOR = 255;

const int MIN_G_COLOR = 0;
const int MAX_G_COLOR = 255;

const int MIN_B_COLOR = 0;
const int MAX_B_COLOR = 255;

// Set circles properties
void generateCircles(sf::CircleShape circleShape, std::vector<sf::CircleShape> &circles)
{				
	circles.push_back(circleShape);

	circles.back().setRadius(rand() % (MAX_RADIUS - MIN_RADIUS) + MIN_RADIUS);
	circles.back().setPosition(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
	circles.back().setFillColor(sf::Color(rand() % (MAX_R_COLOR - MIN_R_COLOR) + MIN_R_COLOR, rand() % (MAX_G_COLOR - MIN_G_COLOR) + MIN_G_COLOR, rand() % (MAX_B_COLOR - MIN_B_COLOR) + MAX_B_COLOR));

	std::cout << "Circle " << circles.size() << "  -  Radius: " << circles.back().getRadius() << "     Pos (X, Y): " << circles.back().getPosition().x << ", " << circles.back().getPosition().y << std::endl;
}

// Draw circles in screen
void drawCircles(sf::RenderWindow &window, std::vector<sf::CircleShape> circles)
{
	for (auto c : circles) 
	{
		window.draw(c);
	}
}

int main() 
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "02 - Pseudo Random Circles");
	
	sf::CircleShape circleShape;
	std::vector<sf::CircleShape> circles;
	sf::Clock clock;

	srand(time(NULL)); // Seed pseudo random numbers

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

		if(clock.getElapsedTime().asSeconds() > CIRCLE_GENERATION_INTERVAL)
		{
			generateCircles(circleShape, circles);
			clock.restart();
		}

		window.clear();

		drawCircles(window, circles);
			
		window.display();
	}

	return 0;
}