//https://www.freefontspro.com/41086/the-ultimate-pixel-font.ttf

#include <SFML/Graphics.hpp>

#include "keyboard.h"
#include "menu.h"

int main()
{
	keyboard keyboard_;
	menu_klasa menu_;
	void(keyboard:: * wsk_klaw)(sf::Event, menu_klasa*);

	sf::RenderWindow window(sf::VideoMode(1280, 720), "GIERECZKA TOMECZKA");

	menu_.get_window(&window);
	wsk_klaw = &keyboard::menu;

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				
			//keyboard_.menu(event, &menu_);
			(keyboard_.*wsk_klaw)(event, &menu_);

		}

	}
	return 0;
}

