#include <SFML/Graphics.hpp>

#include "menu.h"
#include "keyboard.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");


	keyboard keyboard_;
	menu menu_;

	void(keyboard:: * wsk_klaw)(sf::Event, menu);
	wsk_klaw = &keyboard::menu;

	

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
				
			(keyboard_.*wsk_klaw)(event, menu_);


		}





		window.clear();
		window.display();
	}
	return 0;
}