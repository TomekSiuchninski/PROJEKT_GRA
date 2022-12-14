#pragma once

#include <SFML/Graphics.hpp>

class gra_klasa{
public:
	gra_klasa(int trudnosc, int predkosc, int dlugosc, sf::RenderWindow &window);
	void update(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
	void prawo(void);
	void lewo(void);
	void enter(void);
private:




};

