//https://www.freefontspro.com/41086/the-ultimate-pixel-font.ttf


#include <SFML/Graphics.hpp>

#include "keyboard.h"
#include "menu.h"
#include "global.h"
#include "gra.h"

#include "ranking.h"

int main()
{
	keyboard keyboard_;
	menu_klasa menu_;
	//void(keyboard:: * wsk_klaw)(sf::Event, menu_klasa*);
	sf::RenderWindow window(sf::VideoMode(1280, 720), "GIERECZKA TOMECZKA");
	gra_klasa gra;
	menu_.get_window(&window, &gra);
	gra.get_window(&window);
	get_window_r(&window);
	//wsk_klaw = &keyboard::menu;
	//wsk_klaw = &keyboard::gra;
	
	sf::Clock zegar;
	sf::Clock zegar2;



	//window.clear();
	//rysuj_ranking();
	//window.display();


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (!gra.start)keyboard_.menu(event, &menu_);
			if (gra.start) keyboard_.gra(event, &gra);

			//(keyboard_.*wsk_klaw)(event, &menu_);
		}
		if (gra.start == idx::leave || gra.start == idx::end) {
			if (gra.start == idx::leave) menu_.wyswietl_menu();
			menu_.menu_reset();
			gra.start = idx::menu;

		}
		if (gra.start) {
			if (zegar.getElapsedTime().asMilliseconds() > 20) {
				zegar.restart();
				gra.update(window);
				window.clear();
				gra.display(window);
				window.display();

			}
		}
	}
	return 0;
}
