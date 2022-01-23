#include "stdafx.h"
#include "Shop.h"
#include "TurnTable.h"
Shop::ShopMenuResult Shop::Show(sf::RenderWindow& window)
{
	sf::Texture imgshop;
	imgshop.loadFromFile("images/shopl.png");
	shopSpr.setTexture(imgshop);
	shopSpr.setPosition(10,10);
	window.draw(shopSpr);	
	window.draw(textSy);
	window.draw(textSc);
	window.display();

	//cliquez sur la gamme d'achat
	ShopMenuItem sunBtn;		 //180,110,190,210
	sunBtn.rect = { 110,180,210,190 };
	sunBtn.action = sunBuy;
	ShopMenuItem foodBtn;
	foodBtn.rect = { 310,180,210,390 };
	foodBtn.action = foodBuy;
	ShopMenuItem waterBtn;
	waterBtn.rect = { 510,180,210,590 };
	waterBtn.action = waterBuy;
	ShopMenuItem gravityBtn;
	gravityBtn.rect = { 110,380,410,190 };
	gravityBtn.action = gravityBuy;
	ShopMenuItem tempBtn;
	tempBtn.rect = { 310,380,410,390 };
	tempBtn.action = tempBuy;
	ShopMenuItem landBtn;
	landBtn.rect = { 510,380,410,590 };
	landBtn.action = landBuy;
	ShopMenuItem oxygenBtn;
	oxygenBtn.rect = { 110,580,610,190 };
	oxygenBtn.action = oxygenBuy;
	//Quitter la plage de clics
	ShopMenuItem exitButton;
	exitButton.rect={220,420,580,400};
	exitButton.action = Exit;	

	//Placez la plage de clics ¨¤ l'int¨¦rieur du conteneur
	_shopmenuItems.push_back(sunBtn);
	_shopmenuItems.push_back(foodBtn);
	_shopmenuItems.push_back(waterBtn);
	_shopmenuItems.push_back(gravityBtn);
	_shopmenuItems.push_back(tempBtn);
	_shopmenuItems.push_back(landBtn);
	_shopmenuItems.push_back(oxygenBtn);
	_shopmenuItems.push_back(exitButton);

	return GetShopMenuResponse(window);
}
//D¨¦terminez si la position du clic de la souris se trouve ¨¤ l'int¨¦rieur de la zone rectangulaire pour renvoyer le param¨¨tre d'¨¦tat
Shop::ShopMenuResult Shop::HandleClick(int x, int y)
{
	//L'it¨¦rateur parcourt la zone de clic stock¨¦e dans le conteneur de liste pour jugement
	std::list<ShopMenuItem>::iterator it;

	for (it = _shopmenuItems.begin(); it != _shopmenuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.width > y
			&& menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.height > x)
		{
			return (*it).action;
		}
	}

	return Nothing;
}
//R¨¦pondre aux actions de la souris
Shop::ShopMenuResult  Shop::GetShopMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	
	//42 ici! =43 peut ¨ºtre compris comme vrai
	while (42 != 43)
	{

		while (window.pollEvent(menuEvent))
		{
			
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
int Shop::Remainingcash(int m_cash)
{
	if(!font_.loadFromFile("arial.ttf"))
		std::cout<<"cant not find font!";
	textSc.setFont(font_);
	textSc.setColor(sf::Color::Green);
	textSc.setCharacterSize(20);
	textSc.setPosition(shopSpr.getPosition().x+560,shopSpr.getPosition().y+560);
	textSy.setFont(font_);
	textSy.setColor(sf::Color::Green);
	textSy.setCharacterSize(20);
	textSy.setPosition(shopSpr.getPosition().x+440,shopSpr.getPosition().y+560);
	textSy.setString("RemainCash:");
	itoa(m_cash, s_cash, 10);
	textSc.setString(s_cash);
	return m_cash;
}