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
				std::cout << "W";
				meni.up();
			}


			if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
				std::cout << "S";
				meni.down();
			}


			if (event.key.code == sf::Keyboard::Enter) {
				std::cout << "A";
				meni.enter();
			}

		}


	}

};

