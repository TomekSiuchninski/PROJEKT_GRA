#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "gra.h"


class menu_klasa {
public:
	menu_klasa();
	void get_window(sf::RenderWindow* window, gra_klasa *gra);
	void up(void);
	void down(void);
	void enter(void);
	void litera(int lit);
	void menu_reset(void);
	void wyswietl_menu(void);
private:
	sf::RenderWindow* OKNO;
	gra_klasa* GRA;
	int indeks1;
	int indeks2;
	std::string nick;
	std::string tabela[5] = {
		"Nowa gra",
		"Kontunuuj",
		"Ranking graczy",
		"Pomoc",
		"Koniec gry"
	};
	void rysuj_wprowadzanie_nicku(void);
	void rysuj_wybor_trudnosci(void);
	int poziom_trudnosci;
};



