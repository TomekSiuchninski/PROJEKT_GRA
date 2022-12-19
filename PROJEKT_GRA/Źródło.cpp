//https://www.freefontspro.com/41086/the-ultimate-pixel-font.ttf

#include <SFML/Graphics.hpp>

#include "keyboard.h"
#include "menu.h"
#include "global.h"
#include "gra.h"

int main()
{
	keyboard keyboard_;
	menu_klasa menu_;
	//void(keyboard:: * wsk_klaw)(sf::Event, menu_klasa*);
	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "GIERECZKA TOMECZKA");

	menu_.get_window(&window);
	//wsk_klaw = &keyboard::menu;
	//wsk_klaw = &keyboard::gra;
	gra_klasa gra(1, 1, 1, window);

	sf::Clock zegar;
	sf::Clock zegar2;

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//keyboard_.menu(event, &menu_);
			keyboard_.gra(event, &gra);
			//(keyboard_.*wsk_klaw)(event, &menu_);
		}



		if (zegar2.getElapsedTime().asMilliseconds() > 30) {
			zegar2.restart();
			gra.update(window);

		}



		if (zegar.getElapsedTime().asMilliseconds() > 20) {
			zegar.restart();
			window.clear();
			gra.display(window);
			window.display();
			
		}
		
	}
	return 0;
}

