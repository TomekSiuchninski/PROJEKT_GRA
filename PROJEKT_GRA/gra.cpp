#include "gra.h"

#include <iostream>




class blok {
public:
	blok();
	blok(int trudnosc, sf::RenderWindow& window);
	void rysuj(sf::RenderWindow& window);
	float getx(void);
	float gety(void);
	void setx(float x);
	void sety(float y);
//private:
	sf::Texture tx;
	sf::Sprite spr;
	int N;
	int status;
	float x;
	float y;
	int life;
};

float blok::getx(void) {
	return this->x;
}
float blok::gety(void) {
	return this->y;
}
void blok::setx(float x) {
	this->x = x;
}
void blok::sety(float y) {
	this->y = y;
}

blok blocks[32];




class pilka {
public:
	sf::Sprite spr;
	sf::Texture tx;
private:
	float vel;
	sf::Vector2f dir;

};

pilka ball;

class platforma {
public:
	sf::Sprite spr;
	sf::Texture tx;
	float getx(void);
	float gety(void);
	void setx(float x);
	void sety(float y);
private:
	float x;
	float y;
};


float platforma::getx(void) {
	return this->x;
}
float platforma::gety(void) {
	return this->y;
}
void platforma::setx(float x) {
	this->x = x;
}
void platforma::sety(float y) {
	this->y = y;
}


platforma plat;

blok::blok() {

}

blok::blok(int trudnosc, sf::RenderWindow& window) {
	//float x=0;
	//float y=0;
	//tx.loadFromFile("blok1.png");
	//N = 15;
	//bloki = new sf::Sprite[N];
	//for (int i = 0; i < 15; i++) {
	//	x = (i%5)*150;
	//	y = (i%3)*80;
	//	bloki[i].setTexture(tx);
	//	bloki[i].setPosition(sf::Vector2f(x, y));
	//	bloki[i].setScale(sf::Vector2f(1, 1));
	//	
	//}
}




gra_klasa::gra_klasa(int trudnosc, int predkosc, int dlugosc, sf::RenderWindow& window) {
	//sf::Texture txt;
	//txt.loadFromFile("blok1.png");
	//for (int i = 0; i < 32; i++) {
	//	blocks[i].tx = txt;
	//	blocks[i].setx((i % 4) * 150);
	//	blocks[i].sety((i % 8) * 80);
	//	blocks[i].spr.setTexture(txt);
	//}
	sf::Texture txt;
	txt.loadFromFile("blok1.png");
	sf::Texture txt2;
	txt2.loadFromFile("blok2.png");


	for (int i = 0; i < 32; i++) {

		blocks[i].tx = txt;
		blocks[i].setx((i % 8) * 130);
		blocks[i].sety((i / 8) * 70);
		blocks[i].spr.setPosition(blocks[i].getx(), blocks[i].gety());
		blocks[i].spr.setTexture(blocks[i].tx);

	}
}


void blok::rysuj(sf::RenderWindow& window) {
	for (int i = 0; i < 32; i++) {
		window.draw(blocks[i].spr);
	}

}


void gra_klasa::update(sf::RenderWindow& window) {


	sf::Texture txt;
	txt.loadFromFile("blok1.png");

	plat.tx=txt;
	plat.spr.setTexture(plat.tx);
	plat.sety(500);
	std::cout << plat.getx();
	plat.spr.setPosition(plat.getx(), plat.gety());


}

void gra_klasa::display(sf::RenderWindow& window) {
	for (int i = 0; i < 32; i++) {
		window.draw(blocks[i].spr);
	}
	window.draw(ball.spr);
	window.draw(plat.spr);
}

void gra_klasa::prawo(void) {
	plat.setx(plat.getx() + 30);
	//plat.setx(500);
}
void gra_klasa::lewo(void) {
	plat.setx(plat.getx() - 30);
}

void gra_klasa::enter(void) {

}