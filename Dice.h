#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "VisibleGameObject.h"
#include <list>
class Dice :public VisibleGameObject
{
public:
	enum DiceRect { Nothing, Exit, Click };
	Dice();
	virtual ~Dice();
	void diceNum(sf::RenderWindow& window);
	sf::Font _font;  
	char s_Num[3];
	int n_Num=3;
	sf::Text textNum;
	struct diceClick
	{
	public:
		sf::Rect<int> rect;
		DiceRect action;
	};
	DiceRect Show(sf::RenderWindow& window);
private:
	DiceRect GetClickResponse(sf::RenderWindow& window);
	DiceRect HandleClickes(int x, int y);
	std::list<diceClick> _dicerect;
};
//static sf::Text textNum;