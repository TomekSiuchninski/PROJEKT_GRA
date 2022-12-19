#include "gra.h"

#include <iostream>

#define WINDOW_X 1280
#define WINDOW_Y 720
#define BALL_R 15
#define BLOK_X 120
#define BLOK_Y 60

#define PLATFORMA 32
#define PLATFORMA_X 250
#define PLATFORMA_Y 40

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

blok blocks[33];

class pilka {
public:
	sf::Sprite spr;
	sf::Texture tx;
	void kolizja(void);
//private:
	sf::Vector2f vel;
	float x;
	float y;

};
void pilka::kolizja(void) {
	if (this->x > (WINDOW_X - 2*BALL_R) ) {
		this->vel.x = -this->vel.x;
	}
	if (this->x < 0) {
		this->vel.x = -this->vel.x;
	}
	if (this->y < 0) {
		this->vel.y = -this->vel.y;
	}

	for (int i = 0; i < 33; i++) {

		float cx = this->x + BALL_R;
		float cy = this->y + BALL_R;

		float x1 = blocks[i].x;
		float x2 = blocks[i].x+BLOK_X;

		float y1 = blocks[i].y;
        float y2 = blocks[i].y + BLOK_Y;

		if (i == PLATFORMA) {
			x1 = blocks[PLATFORMA].x;
			x2 = blocks[PLATFORMA].x + PLATFORMA_X;
			y1 = blocks[PLATFORMA].y;
			y2 = blocks[PLATFORMA].y + PLATFORMA_Y;
		}
		if((cx + this->vel.x + BALL_R >= x1 && cx + this->vel.x - BALL_R <= x2) && (cy + this->vel.y + BALL_R >= y1 && cy + this->vel.y - BALL_R <= y2) && (blocks[i].life || i==PLATFORMA)) {

			std::cout << "Kolizja"<<i;
			if ((cx + BALL_R < blocks[i].x) && (cx + this->vel.x + BALL_R >= blocks[i].x)) {
				this->vel.x = -this->vel.x;
			}
			if ((cx - BALL_R > x2 && cx + this->vel.x - BALL_R <= x2)) {
				this->vel.x = -this->vel.x;
			}
			if (cy + BALL_R < y1 && cy + this->vel.y + BALL_R >= y1) {
				this->vel.y = -this->vel.y;
			}
			if (cy - BALL_R > y2 && cy + this->vel.y - BALL_R <= y2) {
				this->vel.y = -this->vel.y;
			}
			blocks[i].life--;
		}
	}
	if (this->y > WINDOW_Y) {
		this->vel.y = -this->vel.y;
	}
}


pilka ball;

blok::blok() {

}

blok::blok(int trudnosc, sf::RenderWindow& window) {

}


gra_klasa::gra_klasa(int trudnosc, int predkosc, int dlugosc, sf::RenderWindow& window) {



	for (int i = 0; i < 32; i++) {

		blocks[i].tx.loadFromFile("blok2.png");
		blocks[i].setx((i % 8) * 130+10);
		blocks[i].sety((i / 8) * 70+10);
		blocks[i].spr.setPosition(blocks[i].getx(), blocks[i].gety());
		blocks[i].spr.setTexture(blocks[i].tx);
		blocks[i].life = 1;

	}

	ball.tx.loadFromFile("pilka.png");
	ball.x = 50;
	ball.y = 50;
	ball.vel.x = 12;
	ball.vel.y = -6;
	ball.spr.setTexture(ball.tx);
}

void blok::rysuj(sf::RenderWindow& window) {
	for (int i = 0; i < 32; i++) {
		window.draw(blocks[i].spr);
	}

}

void gra_klasa::update(sf::RenderWindow& window) {

	blocks[PLATFORMA].tx.loadFromFile("platforma.png");
	blocks[PLATFORMA].spr.setTexture(blocks[PLATFORMA].tx);
	blocks[PLATFORMA].sety(600);
	blocks[PLATFORMA].spr.setPosition(blocks[PLATFORMA].x, blocks[PLATFORMA].y);

	ball.x+=ball.vel.x;
	ball.y+=ball.vel.y;
	//std::cout << ball.x<<std::endl;


	ball.spr.setPosition(ball.x, ball.y);

	ball.kolizja();


}

void gra_klasa::display(sf::RenderWindow& window) {
	for (int i = 0; i < 32; i++) {
		if(blocks[i].life) window.draw(blocks[i].spr);
	}
	window.draw(ball.spr);
	window.draw(blocks[PLATFORMA].spr);
}

void gra_klasa::prawo(void) {
	blocks[PLATFORMA].x+=30;
}
void gra_klasa::lewo(void) {
	blocks[PLATFORMA].x-=30;
}

void gra_klasa::enter(void) {

}