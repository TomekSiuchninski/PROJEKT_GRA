#include "menu.h"
#include "ranking.h"

namespace mnu{
	enum { nowa_gra, kontynuuj, ranking, pomoc, koniec };
	namespace nowa_gra_ {
		enum{menu,nick,trudnosc};
	}
}

menu_klasa::menu_klasa() {

}

void menu_klasa::get_window(sf::RenderWindow* window, gra_klasa *gra) {
	GRA = gra;
	OKNO = window;
	wyswietl_menu();

}
void menu_klasa::up(void) {
	if (indeks2 == 0) {
		if (indeks1) indeks1--;
		std::cout << indeks1;
		wyswietl_menu();
	}


	if (indeks1 == mnu::nowa_gra && indeks2 == mnu::nowa_gra_::trudnosc) {
		if (poziom_trudnosci) poziom_trudnosci--;
		rysuj_wybor_trudnosci();
	}

}
void menu_klasa::down(void) {
	if (indeks2 == 0) {
		if (indeks1 < idx::leave) indeks1++;
		std::cout << indeks1;
		wyswietl_menu();
	}

	if (indeks1 == mnu::nowa_gra && indeks2 == mnu::nowa_gra_::trudnosc) {
		if (poziom_trudnosci < 2) poziom_trudnosci++;
		rysuj_wybor_trudnosci();
	}


}
void menu_klasa::enter(void) {
	if (indeks1 == -1) {
		indeks1 = mnu::nowa_gra;
		wyswietl_menu();

	}
	else if (indeks1 == mnu::koniec && indeks2 == 0) {
		OKNO->close();
	}

	else if (indeks1 == mnu::kontynuuj && indeks2 == 0) {
		GRA->on(idx::stop);
	}

	else if (indeks1 == mnu::nowa_gra && indeks2==0) {
		indeks2 = 1;
		rysuj_wprowadzanie_nicku();
	}
	else if (indeks1 == mnu::nowa_gra && indeks2 == 1 && nick.size()) {
		indeks2 = 2;
		std::cout << nick;
		rysuj_wybor_trudnosci();
	}
	else if (indeks1 == mnu::nowa_gra && indeks2 == 2) {
		
		GRA->start_gry(poziom_trudnosci);
		GRA->get_nickname(nick);
	}

	else if (indeks1 == mnu::pomoc && indeks2 == 0) {
		indeks2 = 1;
		GRA->wyswietl_pomoc(OKNO);
		OKNO->display();
	}
	else if (indeks1 == mnu::pomoc && indeks2 == 1) {
		indeks2 = 0;
		wyswietl_menu();
	}


	else if (indeks1 == mnu::ranking && indeks2 == 0) {
		indeks2 = 1;
		//GRA->wyswietl_ranking(OKNO);
		rysuj_ranking();
		OKNO->display();
		
	}
	else if (indeks1 == mnu::ranking && indeks2 == 1) {
		indeks2 = 0;
		wyswietl_menu();
	}

}

void menu_klasa::litera(int lit) {
	std::cout << lit;
	if (indeks1 == mnu::nowa_gra && lit != sf::Keyboard::Backspace && indeks2 == 1) {
		nick += (lit+65);
		rysuj_wprowadzanie_nicku();
	}
	else if (indeks1 == 0 && lit == sf::Keyboard::Backspace && nick.size() && indeks2 == 1) {
		nick.pop_back();
		rysuj_wprowadzanie_nicku();
	}
	
}

void menu_klasa::wyswietl_menu(void) {
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
	text.setCharacterSize(50); // in pixels, not points!
	text.setFillColor(sf::Color::Yellow);

	for (int i = 0; i < 5; i++) {
		int dlugosc = tabela[i].size();
		text.setString(tabela[i]);
		text.setPosition(1280 / 2 - dlugosc * 10, 120 + 100 * i);
		//std::cout << dlugosc <<" ";
		OKNO->draw(text);
	}


	text.setString(">");
	text.setPosition(1280 / 2 - tabela[indeks1].size() * 10 - 50, 120 + 100 * indeks1);
	OKNO->draw(text);
	OKNO->display();
}

void menu_klasa::rysuj_wprowadzanie_nicku(void) {
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
	text.setCharacterSize(80); // in pixels, not points!
	text.setFillColor(sf::Color::Yellow);

	std::string t = "Podaj nick:";

	text.setString(t);
	text.setPosition(1280 / 2 - t.size() * 18, 220);
	OKNO->draw(text);


	text.setCharacterSize(50); // in pixels, not points!
	text.setString(nick+"|");
	text.setPosition(1280 / 2 - nick.size() * 16, 370);
	OKNO->draw(text);
	
	OKNO->display();
	//GRA->update(*OKNO);
	

}

void menu_klasa::rysuj_wybor_trudnosci(void) {
	sf::Font font;
	if (!font.loadFromFile("UltimatePixelFont.ttf"))
	{
		// error...
	}
	sf::Sprite tlo;
	sf::Texture tx;
	tx.loadFromFile("main.png");
	tlo.setTexture(tx);
	

	OKNO->clear();
	OKNO->draw(tlo);
	sf::Text text;
	text.setFont(font); // font is a sf::Font
	text.setCharacterSize(80); // in pixels, not points!
	text.setFillColor(sf::Color::Red);

	std::string t = "Wybierz poziom trudnosci:";

	text.setString(t);
	text.setPosition(1280 / 2 - t.size() * 18 - 50 , 40);
	OKNO->draw(text);

	//sf::Texture tx;
	tx.loadFromFile("blok_drewno.png");
	sf::Sprite sp;
	sp.setTexture(tx);
	sp.setPosition(330, 220);
	OKNO->draw(sp);

	tx.loadFromFile("blok_kamien.png");
	sp.setTexture(tx);
	sp.setPosition(330, 220+120);
	OKNO->draw(sp);

	tx.loadFromFile("blok_metal.png");
	sp.setTexture(tx);
	sp.setPosition(330, 220+120+120);
	OKNO->draw(sp);

	text.setCharacterSize(50);
	switch (poziom_trudnosci) {
	case 0:
		text.setString("AMATOR");
		text.setPosition(500, 220);
	break;
	case 1:
		text.setString("ZAAWANSOWANY");
		text.setPosition(500, 220 + 120);
	break;
	case 2:
		text.setString("MISTRZ!");
		text.setPosition(500, 220 + 120 + 120);
	break;
	}
	OKNO->draw(text);
			


	OKNO->display();
	//GRA->update(*OKNO);
}

void menu_klasa::menu_reset(void) {
	this->indeks1 = -1;

	this->indeks2 = 0;
}

