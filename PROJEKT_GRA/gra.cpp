#include "gra.h"

#include <SFML/Graphics.hpp>

class blok {
public:
	blok(float x, float y, int life);
private:
	float x;
	float y;
	int life;
	
};

class pilka {
public:

private:
	float vel;
	sf::Vector2f dir;

};

class platforma {
public:
private:
	float x;
	float y;
};

blok::blok(float x,float y, int life) {
	this->x = x;
	this->y = y;
	this->life = life;
}

gra::gra(int trudnosc, int predkosc) {

}