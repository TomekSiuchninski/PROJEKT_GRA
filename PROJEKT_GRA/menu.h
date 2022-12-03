#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class menu{

public:
	void get_window(sf::RenderWindow * window) {

		OKNO = window;
		wyswietl_menu();

	}
	void up(void) {
		indeks--;
		std::cout << indeks;
		wyswietl_menu();
	}
	void down(void) {
		indeks++;
		std::cout << indeks;
		wyswietl_menu();
	}
	void enter(void) {

	}
private:
	sf::RenderWindow * OKNO;
	int indeks;
	std::string tabela[5] = {
		"Nowa gra",
		"Wczytaj gre",
		"Ranking graczy",
		"Pomoc",
		"Koniec gry"
	};

	void wyswietl_menu(void) {
		sf::Font font;
		if (!font.loadFromFile("UltimatePixelFont.ttf"))
		{
			// error...
		}

		OKNO->clear();
		sf::Text text;
		text.setFont(font); // font is a sf::Font
		text.setCharacterSize(50); // in pixels, not points!
		text.setFillColor(sf::Color::Yellow);

		for (int i = 0; i < 5; i++) {
			int dlugosc = tabela[i].size();
			text.setString(tabela[i]);
			text.setPosition(1280/2-dlugosc*10, 120+100 * i);
			//std::cout << dlugosc <<" ";
			OKNO->draw(text);
		}


		text.setString(">");
		text.setPosition(1280 / 2 - tabela[indeks].size() * 10 - 50, 120 + 100 * indeks);
		OKNO->draw(text);

		OKNO->display();
	}
	


};

