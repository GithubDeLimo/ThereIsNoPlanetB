#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>
class Shop
{
public:
	enum ShopMenuResult { Nothing, Exit, sunBuy,foodBuy,waterBuy,gravityBuy,tempBuy,landBuy,oxygenBuy };
	sf::Font font_;  
	char s_cash[3];
	//static int m_cash; 
	//Utiliser une structure pour stocker les informations de param¨¨tre d'attribut de la zone de clic rectangulaire
	struct ShopMenuItem
	{
	public:
		//Objet mod¨¨le utilis¨¦ pour stocker des points pour l'¨¦tendue de la zone rectangulaire
		//Un point contient deux valeurs de coordonn¨¦es et les deux points forment une zone rectangulaire
		sf::Rect<int> rect;
		ShopMenuResult action;
	};
	//sf::Sprite Something[7];
	//sf::Texture imgSomething[7];
	char SomethingName[64];
	sf::Sprite shopSpr;
	int Remainingcash(int m_cash);	 //Afficher l'argent restant
	ShopMenuResult Show(sf::RenderWindow& window);
private:
	ShopMenuResult GetShopMenuResponse(sf::RenderWindow& window);
	ShopMenuResult HandleClick(int x, int y);
	//Conteneur pour stocker la zone touch¨¦e
	std::list<ShopMenuItem> _shopmenuItems;
};
static sf::Text textSc,textSy;

