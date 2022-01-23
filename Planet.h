#pragma once
#include "VisibleGameObject.h"
#include "Game.h"
#include "SFML\Audio.hpp"
// VisibleGameObject
class Planet :public VisibleGameObject
{
public:
	Planet();
	virtual ~Planet();
	void Planet::Update(float elapsedTime);
	struct Map
	{
	public:
		int x; //D¨¦finir un point sur la carte de la plan¨¨te£¬x
		int y;  //la coordonn¨¦e y du point
	}maps[8];
	int i=3;int j=-1;
	sf::Vector2f starPos = {-50,-50};
	float _elapsedTimeSinceStart;  //temps de jeu total
private:
	float _velocity;  //vitesse
	int px=0,py=0;
	float LinearVelocityX(int x); //Vitesse de ligne horizontale
	float LinearVelocityY(int y);  //vitesse de la ligne verticale
	
};
