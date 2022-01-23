#pragma once

class TurnTable
{
public:
	float turnaround(sf::Clock fsecond);
	int Show(sf::RenderWindow& window);
	sf::Sprite sprite,pan;
	float angle=0.f,_angle=0.f;
	int z_cash;
};
static int n_cash;