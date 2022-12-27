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
	void F1(void);
	void wyswietl_pomoc(sf::RenderWindow* window);
	void wyswietl_ranking(sf::RenderWindow* window);
	void get_window(sf::RenderWindow* window);
	void on(void);
	void off(void);
	int start;
private:
	sf::RenderWindow* OKNO;
	



};

