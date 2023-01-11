#include "gra.h"



#include <iostream>
#include <cmath>

#include "ranking.h"

#define WINDOW_X 1050
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
	sf::Texture tx_br;
	sf::Sprite spr;
	sf::Sprite spr_br;
	int N;
	int status;
	float x;
	float y;
	float life;
	float max_life;
	float x_mem;
	float y_mem;

};

void gra_klasa::get_window(sf::RenderWindow* window) {
	OKNO = window;

}


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
	sf::Vector2f vel_mem;
	float speed;
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
			if (i != PLATFORMA) {
				std::cout << "Kolizja" << i;
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
				if (i != PLATFORMA) blocks[i].life--;
			}
			else {
				if ((cx + BALL_R < blocks[i].x) && (cx + this->vel.x + BALL_R >= blocks[i].x)) {
					this->vel.x = -this->vel.x;
				}
				if ((cx - BALL_R > x2 && cx + this->vel.x - BALL_R <= x2)) {
					this->vel.x = -this->vel.x;
				}
				if (cy + BALL_R < y1 && cy + this->vel.y + BALL_R >= y1) {
					float v = sqrt(this->vel.y * this->vel.y + this->vel.x * this->vel.x);
					this->vel.x = 20*(cx-(x1+x2)/2)/PLATFORMA_X;
					this->vel.y = -sqrt(v * v - this->vel.x * this->vel.x);
				}

			}

			
		}
	}
	if (this->y > WINDOW_Y) {
		//this->vel.y = -this->vel.y;
		blocks[PLATFORMA].status = platforma_status::przyklejona;
		blocks[PLATFORMA].life--;
	}
}


pilka ball;

blok::blok() {

}

blok::blok(int trudnosc, sf::RenderWindow& window) {

}


gra_klasa::gra_klasa() {


	
}

void blok::rysuj(sf::RenderWindow& window) {
	for (int i = 0; i < 32; i++) {
		window.draw(blocks[i].spr);
	}

}

void gra_klasa::update(sf::RenderWindow& window) {
	if(start == idx::gra) czas_gry++;
	blocks[PLATFORMA].tx.loadFromFile("platforma.png");
	blocks[PLATFORMA].spr.setTexture(blocks[PLATFORMA].tx);
	blocks[PLATFORMA].sety(600);
	blocks[PLATFORMA].spr.setPosition(blocks[PLATFORMA].x, blocks[PLATFORMA].y);


	//std::cout << blocks[PLATFORMA].status << std::endl;

	if (blocks[PLATFORMA].status == platforma_status::przyklejona) {
		ball.x = blocks[PLATFORMA].x + PLATFORMA_X / 2 - BALL_R;
		ball.y = blocks[PLATFORMA].y - 2*BALL_R;
		//std::cout << (WINDOW_X / 2 - (blocks[PLATFORMA].x + PLATFORMA_X / 2 - BALL_R)) << std::endl;
		ball.vel.x = 0.03*(WINDOW_X/2 - (blocks[PLATFORMA].x + PLATFORMA_X / 2 - BALL_R) ) ;
		
		ball.vel.y =-sqrt(ball.speed* ball.speed - ball.vel.x* ball.vel.x);
	}
	else {
		ball.x += ball.vel.x;
		ball.y += ball.vel.y;
	}

	//std::cout << ball.x<<std::endl;
	ball.spr.setPosition(ball.x, ball.y);

	ball.kolizja();
	sf::Texture d1;
	sf::Texture d2;
	sf::Texture d3;
	sf::Texture d4;
	d1.loadFromFile("d1.png");
	d2.loadFromFile("d2.png");
	d3.loadFromFile("d3.png");
	d4.loadFromFile("d4.png");


	for (int i = 0; i < 32; i++) {


		if (blocks[0].max_life == 2) {
			if (blocks[i].life == 2) blocks[i].tx_br = blocks[i].tx;
			if (blocks[i].life == 1) blocks[i].tx_br = d3;
		}
		else if (blocks[0].max_life == 3) {
			if (blocks[i].life == 3) blocks[i].tx_br = blocks[i].tx;
			if (blocks[i].life == 2) blocks[i].tx_br = d2;
			if (blocks[i].life == 1) blocks[i].tx_br = d4;
		}
		else if (blocks[0].max_life == 4) {
			if (blocks[i].life == 4) blocks[i].tx_br = blocks[i].tx;
			if (blocks[i].life == 3) blocks[i].tx_br = d1;
			if (blocks[i].life == 2) blocks[i].tx_br = d2;
			if (blocks[i].life == 1) blocks[i].tx_br = d3;
		}
		blocks[i].spr_br.setTexture(blocks[i].tx_br);

	}
	//std::cout << ball.x << std::endl;
	if (blocks[PLATFORMA].life <0) {
		przegrana();
	}
	int check = 32;
	for (int i = 0; i < 32; i++) if (blocks[i].life == 0) check--;
	if(!check) wygrana();


}

void gra_klasa::display(sf::RenderWindow& window) {
	//std::cout << start << std::endl;
	sf::Sprite tlo;
	sf::Texture tx;

	tx.loadFromFile("game.png");
	tlo.setTexture(tx);
	OKNO->draw(tlo);
	for (int i = 0; i < 32; i++) {
		if (blocks[i].life) {
			window.draw(blocks[i].spr);
			window.draw(blocks[i].spr_br);
		}
	}
	window.draw(ball.spr);
	window.draw(blocks[PLATFORMA].spr);

	sf::Font font;
	if (!font.loadFromFile("UltimatePixelFont.ttf"))
	{
		// error...
	}



	sf::Sprite serce;
	sf::Texture txt;
	txt.loadFromFile("serce.png");
	
	serce.setTexture(txt);
	serce.setScale(0.15f, 0.15f);

	for (int i = 0; i < blocks[PLATFORMA].life; i++) {
		serce.setPosition(1075 + i * 70, 620);
		OKNO->draw(serce);
	}
	sf::Text text;
	text.setFont(font); // font is a sf::Font
	text.setCharacterSize(40); // in pixels, not points!
	text.setFillColor(sf::Color::Magenta);

	std::string t = "Szanse:";

	text.setString(t);
	text.setPosition(1095, 555);
	OKNO->draw(text);

	int s = czas_gry / 50;

	int dig4 = s % 10;
	int dig3 = (s / 10) % 6;
	int dig2 = (s / 60) % 10;


	//std::cout << s << std::endl;
	t = std::to_string(dig2) + ":"+ std::to_string(dig3) + std::to_string(dig4);
	text.setPosition(1125, 180);
	text.setString(t);
	OKNO->draw(text);

	t = "Czas gry:";
	text.setPosition(1085, 120);
	text.setString(t);
	OKNO->draw(text);
	

	if (start == idx::stop) wyswietl_pomoc(OKNO);
	if (start == idx::escape) wyswietl_escape(OKNO);
	if (start == idx::end) rysuj_ranking();
}

void gra_klasa::prawo(void) {
	if(blocks[PLATFORMA].x< WINDOW_X - PLATFORMA_X ) blocks[PLATFORMA].x+=30;
}
void gra_klasa::lewo(void) {
	if (blocks[PLATFORMA].x) blocks[PLATFORMA].x-=30;
}
void gra_klasa::Escape(void) {
	if (start == 1 || start==2) {
		this->start = 3;
		ball.vel_mem = ball.vel;
		ball.vel.x = 0;
		ball.vel.y = 0;
		blocks[PLATFORMA].x_mem = blocks[PLATFORMA].x;
		blocks[PLATFORMA].y_mem = blocks[PLATFORMA].y;
	}
	else if (start == 3) {
		this->start = 1;
		ball.vel = ball.vel_mem;
		blocks[PLATFORMA].x = blocks[PLATFORMA].x_mem;
		blocks[PLATFORMA].y = blocks[PLATFORMA].y_mem;
	}
	std::cout << this->start;
}
void gra_klasa::enter(void) {

	if (start == idx::escape) {
		start = idx::leave;
	}
	std::cout << start << std::endl;
}

void gra_klasa::space(void) {
	if (blocks[PLATFORMA].status == platforma_status::przyklejona && blocks[PLATFORMA].life>=0 ) blocks[PLATFORMA].status = platforma_status::lot;
}

void gra_klasa::wyswietl_pomoc(sf::RenderWindow* window) {
	sf::Font font;
	if (!font.loadFromFile("UltimatePixelFont.ttf"))
	{
		// error...
	}

	sf::Sprite spr;
	sf::Texture tx;

	tx.loadFromFile("main.png");
	spr.setTexture(tx);


	OKNO->clear();
	OKNO->draw(spr);
	sf::Text text;
	text.setFont(font); // font is a sf::Font
	text.setCharacterSize(70); // in pixels, not points!
	text.setFillColor(sf::Color(251,87,17));
	text.setString("WCISNIJ F1, ABY KONTYNUOWAC");
	text.setPosition(115, 580);
	OKNO->draw(text);

	sf::Sprite spr2;
	sf::Texture tx2;
	tx2.loadFromFile("platforma.png");
	spr2.setTexture(tx2);
	spr2.setPosition(100, 100);
	OKNO->draw(spr2);

	sf::Sprite spr3;
	sf::Texture tx3;
	tx3.loadFromFile("pilka.png");
	spr3.setTexture(tx3);
	spr3.setPosition(180, 64);
	OKNO->draw(spr3);


	sf::Text text2;
	text2.setFont(font); // font is a sf::Font
	text2.setCharacterSize(50); // in pixels, not points!
	text2.setFillColor(sf::Color(1, 240, 60));
	text2.setString("Aby rozpoczac, wcisnij spacje");
	text2.setPosition(400, 100);
	OKNO->draw(text2);

	sf::Text text3;
	text3.setFont(font); // font is a sf::Font
	text3.setCharacterSize(50); // in pixels, not points!
	text3.setFillColor(sf::Color(184, 177, 54));
	text3.setString("<- Steruj platforma przy pomocy strzalek ->");
	text3.setPosition(80, 200);
	OKNO->draw(text3);

	sf::Text text4;
	text4.setFont(font); // font is a sf::Font
	text4.setCharacterSize(80); // in pixels, not points!
	text4.setFillColor(sf::Color(193, 20, 20));
	text4.setString("ZNISZCZ JE WSZYSTKIE!");
	text4.setPosition(200, 330);
	OKNO->draw(text4);

	sf::Sprite bl1;
	sf::Texture bltx1;
	bltx1.loadFromFile("blok_drewno.png");
	bl1.setTexture(bltx1);
	bl1.setPosition(240, 450);
	bl1.setScale(2, 2);
	OKNO->draw(bl1);

	sf::Sprite bl2;
	sf::Texture bltx2;
	bltx2.loadFromFile("blok_kamien.png");
	bl2.setTexture(bltx2);
	bl2.setPosition(540, 450);
	bl2.setScale(2, 2);
	OKNO->draw(bl2);

	sf::Sprite bl3;
	sf::Texture bltx3;
	bltx3.loadFromFile("blok_metal.png");
	bl3.setTexture(bltx3);
	bl3.setPosition(840, 450);
	bl3.setScale(2, 2);
	OKNO->draw(bl3);

	//OKNO->display();
	//GRA->update(*OKNO);
}



void gra_klasa::wyswietl_ranking(sf::RenderWindow* window) {
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
	text.setFillColor(sf::Color::Green);

	std::string t = "LISTA KOXOW PVP:";

	text.setString(t);
	text.setPosition(50, 220);
	OKNO->draw(text);

	text.setString("AUU SZLALALA");
	text.setPosition(1280 / 2 - 10, 420);
	OKNO->draw(text);

	OKNO->display();
	//GRA->update(*OKNO);
}

void gra_klasa::wyswietl_escape(sf::RenderWindow* window) {
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
	text.setFillColor(sf::Color::Green);

	std::string t = "WYCHODZISZ?:";

	text.setString(t);
	text.setPosition(50, 220);
	OKNO->draw(text);

	text.setString("AUU SZLALALA");
	text.setPosition(1280 / 2 - 10, 420);
	OKNO->draw(text);

	//OKNO->display();
}




void gra_klasa::on(int st) {
	this->start = st;
};


void gra_klasa::F1(void) {
	if (start == idx::gra) {
		this->start = idx::stop;
		ball.vel_mem = ball.vel;
		ball.vel.x = 0;
		ball.vel.y = 0;
		blocks[PLATFORMA].x_mem = blocks[PLATFORMA].x;
		blocks[PLATFORMA].y_mem = blocks[PLATFORMA].y;
	}
	else if (start == idx::stop) {
		this->start = idx::gra;
		ball.vel = ball.vel_mem;
		blocks[PLATFORMA].x = blocks[PLATFORMA].x_mem;
		blocks[PLATFORMA].y = blocks[PLATFORMA].y_mem;
	}
	std::cout << this->start;
	
}


int trud;
void gra_klasa::start_gry(int trudnosc) {
	trud = trudnosc;
	on(idx::gra);
	czas_gry = 0;
	blocks[0].max_life = trudnosc+2;


	blocks[PLATFORMA].status = 0;
	blocks[PLATFORMA].life = 3;
	ball.tx.loadFromFile("pilka.png");
	ball.spr.setTexture(ball.tx);





	switch (trudnosc) {
	case 0:
		for (int i = 0; i < 32; i++) {
			blocks[i].tx.loadFromFile("blok_drewno.png");
			blocks[i].setx((i % 8) * 130 + 10);
			blocks[i].sety((i / 8) * 70 + 10);
			blocks[i].spr.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr_br.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr.setTexture(blocks[i].tx);
			blocks[i].life = 2;
			ball.speed = 13;
		}
		break;
	case 1:
		for (int i = 0; i < 32; i++) {
			blocks[i].tx.loadFromFile("blok_kamien.png");
			blocks[i].setx((i % 8) * 130 + 10);
			blocks[i].sety((i / 8) * 70 + 10);
			blocks[i].spr.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr_br.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr.setTexture(blocks[i].tx);
			blocks[i].life = 3;
			ball.speed = 17;
		}
		break;
	case 2:
		for (int i = 0; i < 32; i++) {
			blocks[i].tx.loadFromFile("blok_metal.png");
			blocks[i].setx((i % 8) * 130 + 10);
			blocks[i].sety((i / 8) * 70 + 10);
			blocks[i].spr.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr_br.setPosition(blocks[i].getx(), blocks[i].gety());
			blocks[i].spr.setTexture(blocks[i].tx);
			blocks[i].life = 4;
			ball.speed = 22;
		}
		break;
	}


}

std::string nick;

void gra_klasa::get_nickname(std::string nickname) {
	nick = nickname;
}

void gra_klasa::wygrana(void) {
	int pkt = 100 * blocks[PLATFORMA].life + (9000 - czas_gry) * (trud + 1) / 2;
	dodaj(pkt, nick);

	rysuj_ranking();
	OKNO->display();
	
	on(idx::end);
	std::cout << "WYGRANA" << std::endl;
}

void gra_klasa::przegrana(void) {
	on(idx::end);
	dodaj(1, nick);
	rysuj_ranking();
	OKNO->display();
	std::cout << "PRZEGRANA" << std::endl;
}