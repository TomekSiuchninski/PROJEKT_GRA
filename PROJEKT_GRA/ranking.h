#pragma once


	class rank;


	void dodaj(int pkt, std::string nickname);
	void zapisz(rank* dodany);
	void rysuj_ranking();
	void sortuj(rank* wsk, int liczba_rekordow);
	void get_window_r(sf::RenderWindow* window);


