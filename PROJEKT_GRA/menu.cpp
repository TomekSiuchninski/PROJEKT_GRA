#include "menu.h"

menu_klasa::menu_klasa() {
	indeks = 0;
}

void menu_klasa::get_window(sf::RenderWindow* window) {

	OKNO = window;
	wyswietl_menu();

}
void menu_klasa::up(void) {
	if(indeks) indeks--;
	std::cout << indeks;
	wyswietl_menu();
}
void menu_klasa::down(void) {
	if(indeks<4) indeks++;
	std::cout << indeks;
	wyswietl_menu();
}
void menu_klasa::enter(void) {
	if(indeks==4) OKNO->close();
}
void menu_klasa::wyswietl_menu(void) {
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
		text.setPosition(1280 / 2 - dlugosc * 10, 120 + 100 * i);
		//std::cout << dlugosc <<" ";
		OKNO->draw(text);
	}


	text.setString(">");
	text.setPosition(1280 / 2 - tabela[indeks].size() * 10 - 50, 120 + 100 * indeks);
	OKNO->draw(text);
	OKNO->display();
}