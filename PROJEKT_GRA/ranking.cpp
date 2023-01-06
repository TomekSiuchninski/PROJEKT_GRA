#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <string>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>

#include "ranking.h"
sf::RenderWindow* OKNO;

class rank {
public:
	std::string nick;
	int pkt;
	std::string data;
};



void zapisz(rank* dodany) {

	//std::cout << dodany->data << " "+dodany->nick << " " + dodany->pkt << std::endl;

	FILE* fp;
	fp = fopen("ranking.dat", "a+b");
	fseek(fp, 0, SEEK_END);
	if (fp == NULL) std::cout << "BLAD";
	else fwrite(dodany, sizeof(rank), 1, fp);
	fclose(fp);
	//rysuj_ranking();
}

void dodaj(int pkty, std::string nickname) {

	time_t czas;
	struct tm* aktualnyCzas;
	time(&czas);
	aktualnyCzas = localtime(&czas);

	std::string rok = std::to_string(aktualnyCzas->tm_year - 100);
	std::string miesiac = std::to_string(aktualnyCzas->tm_mon + 1);
	if (aktualnyCzas->tm_mon + 1 < 10) miesiac = "0" + miesiac;
	std::string dzien = std::to_string(aktualnyCzas->tm_mday);
	if (aktualnyCzas->tm_mday< 10) dzien = "0" + dzien;

	std::string str_data = dzien +"-"+ miesiac + "-" + rok;

	std::string godzin = std::to_string(aktualnyCzas->tm_hour);
	if (aktualnyCzas->tm_hour<10) godzin = "0" + godzin;
	std::string minut = std::to_string(aktualnyCzas->tm_min);
	if (aktualnyCzas->tm_min<10) minut = "0" + minut;

	std::string godzina = godzin + ":" + minut;

	std::string dat = str_data + " " + godzina;
	//std::cout << dat << std::endl;
	//std::cout << nickname;


	rank nowy;
	nowy.pkt = pkty;
	nowy.nick = nickname;
	nowy.data = dat;

	zapisz(&nowy);

}




void rysuj_ranking(void ) {
	FILE* fp;
	fp = fopen("ranking.dat", "a+b");

	fseek(fp, 0, SEEK_END);
	int liczba = ftell(fp) / sizeof(rank);

	rank* odczytane;
	odczytane = new rank[liczba];

	fseek(fp, 0, SEEK_SET);

		rank buf;
		for (int i = 0; i < liczba; i++) {

			fread(&buf, sizeof(rank), 1, fp);
			odczytane[i] = buf;
		}


	fclose(fp);
	sortuj(odczytane, liczba);


	sf::Sprite tlo;
	sf::Texture tx;
	tx.loadFromFile("main.png");
	tlo.setTexture(tx);


	sf::Font font;
	if (!font.loadFromFile("UltimatePixelFont.ttf"))
	{
		// error...
	}

	OKNO->clear();
	OKNO->draw(tlo);
	sf::Text text;
	text.setFont(font); // font is a sf::Font

	text.setPosition(370, 10);
	text.setCharacterSize(80); // in pixels, not points!
	text.setFillColor(sf::Color::Yellow);

	text.setString("Ranking graczy:");
	OKNO->draw(text);

	for (int j = 0; j < 10; j++) {
		rank empty;
		empty.nick = " ";
		empty.pkt = 0;
		empty.data = " ";

		rank do_wyswietlenia;
		if (j > liczba - 1) do_wyswietlenia = empty;
		else do_wyswietlenia = odczytane[j];

		text.setCharacterSize(30); // in pixels, not points!
		text.setFillColor(sf::Color::Magenta);

		text.setString(std::to_string(j + 1)+".");
		text.setPosition(250, 180 + 50 * j);
		OKNO->draw(text);

		text.setString(do_wyswietlenia.nick);
		text.setPosition(400, 180 + 50 * j);
		OKNO->draw(text);

		text.setString(do_wyswietlenia.data);
		text.setPosition(600, 180 + 50 * j);
		OKNO->draw(text);

		if(do_wyswietlenia.pkt) text.setString(std::to_string(do_wyswietlenia.pkt));
		text.setPosition(900, 180 + 50 * j);
		OKNO->draw(text);

	}

	text.setCharacterSize(30); // in pixels, not points!
	text.setFillColor(sf::Color::Red);



	text.setString("Nick gracza:");
	text.setPosition(400, 120);
	OKNO->draw(text);

	text.setString("Data gry:");
	text.setPosition(600, 120);
	OKNO->draw(text);

	text.setString("Zdobyte punkty:");
	text.setPosition(900, 120);
	OKNO->draw(text);



}

void sortuj(rank* wsk,int liczba_rekordow) {


	rank temp;
	for (int i = 0; i < liczba_rekordow - 1; i++) {
		for (int j = 0; j < liczba_rekordow - i - 1; j++) {
			if (wsk[j].pkt < wsk[j + 1].pkt) {
				temp = wsk[j];
				wsk[j] = wsk[j + 1];
				wsk[j + 1] = temp;
			}

		}
	}

}

void get_window_r(sf::RenderWindow* window) {
	OKNO = window;

}