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

void keyboard::gra(sf::Event event, gra_klasa* men) {
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Right) {
			men->prawo();
		}
		else if (event.key.code == sf::Keyboard::Left) {
			men->lewo();
		}
		else if (event.key.code == sf::Keyboard::Enter) {
			men->enter();
		}
		else if (event.key.code == sf::Keyboard::Space) {
			men->space();
		}
		else if (event.key.code == sf::Keyboard::F1) {
			men->F1();
		}
		else if (event.key.code == sf::Keyboard::Escape) {
			men->Escape();
		}
	}
}