#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include "menu.h"

class keyboard{
public:
	void menu(sf::Event event, menu meni) {
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
				meni.up();
			}


			if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
				meni.down();
			}


			if (event.key.code == sf::Keyboard::Enter) {
				meni.enter();
			}

		}


	}

};

