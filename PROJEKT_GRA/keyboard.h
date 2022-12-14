#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include "menu.h"
#include "gra.h"

 


class keyboard{
public:
	void menu(sf::Event event, menu_klasa* men);
	void gra(sf::Event event, gra_klasa* men);
};
