#include "keyboard.h"


void keyboard::menu(sf::Event event, menu_klasa* men){
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
			men->up();
		}
		if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
			men->down();
		}
		if (event.key.code == sf::Keyboard::Enter) {
			men->enter();
		}

	}


}

