#include "keyboard.h"
#include "global.h"

void keyboard::menu(sf::Event event, menu_klasa* men){


	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Up) {
			men->up();
		}
		else if (event.key.code == sf::Keyboard::Down) {
			men->down();
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			men->enter();
		}
		else if ( (event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) || event.key.code== sf::Keyboard::Backspace) {
			men->litera(event.key.code);
		}

	}


}

