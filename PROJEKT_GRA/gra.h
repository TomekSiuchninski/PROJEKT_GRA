#pragma once

#include <SFML/Graphics.hpp>

class gra_klasa{
public:
	gra_klasa();
	void update(sf::RenderWindow& window);
	void display(sf::RenderWindow& window);
	void prawo(void);
	void lewo(void);
	void enter(void);
	void space(void);
	void F1(void);
	void wyswietl_pomoc(sf::RenderWindow* window);
	void wyswietl_ranking(sf::RenderWindow* window);
	void wyswietl_escape(sf::RenderWindow* window);
	void get_window(sf::RenderWindow* window);
	void on(int st);
	int start;
	void start_gry(int trudnosc);
	void Escape(void);
private:
	sf::RenderWindow* OKNO;
	int czas_gry;
	void wygrana(void);
	void przegrana(void);


};

