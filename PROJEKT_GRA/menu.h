#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>


	class menu_klasa {
	public:
		menu_klasa();
		void get_window(sf::RenderWindow* window);
		void up(void);
		void down(void);
		void enter(void);
	private:
		sf::RenderWindow* OKNO;
		int indeks;
		std::string tabela[5] = {
			"Nowa gra",
			"Wczytaj gre",
			"Ranking graczy",
			"Pomoc",
			"Koniec gry"
		};
		void wyswietl_menu(void);
	};



