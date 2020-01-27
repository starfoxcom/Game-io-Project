#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

int main()
{
	sf::RenderWindow wind(sf::VideoMode(500, 500), "window");

	sf::Event event;
	while (wind.isOpen())
	{
		while (wind.pollEvent(event))
		{
			if (event.type== sf::Event::Closed)
				wind.close();
			if (event.key.code == sf::Keyboard::Escape)
			{
				wind.close();
			}

		}
		wind.clear(sf::Color(100, 0, 100, 255));
		wind.display();
	}
	return 0;
}