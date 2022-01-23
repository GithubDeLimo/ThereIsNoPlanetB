#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play,Mercure,Mars,Jupiter,Saturne,V¨¦nus,Neptune,Uranus };
	//Utiliser une structure pour stocker les informations de param¨¨tre d'attribut de la zone de clic rectangulaire
	struct MenuItem
	{
	public:
		//Objet mod¨¨le utilis¨¦ pour stocker des points pour l'¨¦tendue de la zone rectangulaire
		//Un point contient deux valeurs de coordonn¨¦es et les deux points forment une zone rectangulaire
		sf::Rect<int> rect;
		MenuResult action;
	};
	sf::Sprite xingqiu[7];
	sf::Texture imgxingqiu[7];
	char xingqiuName[64];
	MenuResult Show(sf::RenderWindow& window);
	int sun=0,land=0,gravity=0,water=0,food=0,oxygen=0,temperatures=0;
private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	//Conteneur pour stocker la zone touch¨¦e
	std::list<MenuItem> _menuItems;
};
