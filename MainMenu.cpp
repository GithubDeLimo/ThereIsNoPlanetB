#include "stdafx.h"
#include "MainMenu.h"
MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{	
	sf::Texture  imgvis; sf::Sprite spvis;
	if(!imgvis.loadFromFile("images/visi.jpg"))
	   std::cout<<"visi image not found!"<<std::endl;
	spvis.setTexture(imgvis);
	spvis.setScale(0.8f,0.8f);
	spvis.setPosition(20,20);
	window.draw(spvis);
	MenuItem playButton[7];
	for(int i=0;i<7;i++)
	{
		sprintf(xingqiuName,"images/xingqiu%d.png",i);
		imgxingqiu[i].loadFromFile(xingqiuName);
		xingqiu[i].setTexture(imgxingqiu[i]);
		xingqiu[i].setScale(0.6f,0.6f);
		if(i<3)
		{xingqiu[i].setPosition(i*250+200,131);}
		else
		{
			xingqiu[i].setPosition(i*250+10-750,403);
		}
		if(i==0)
		{playButton[i].action=Mercure;playButton[i].rect = {200,131,301,400};}
		if(i==1)
		{playButton[i].action=Mars;playButton[i].rect = {450,131,331,650};}
		if(i==2)
		{playButton[i].action = Jupiter; playButton[i].rect = {700,131,331,900};}  //playButton[i].rect = {560,131,331,760}
		if(i==3)
		{playButton[i].action=Saturne;playButton[i].rect = {10,403,603,200};}
		if(i==4)
		{playButton[i].action=V¨¦nus;playButton[i].rect = {260,403,603,400};}
		if(i==5)
		{playButton[i].action=Neptune;playButton[i].rect = {510,403,703,720};}
		if(i==6)
		{playButton[i].action=Uranus;playButton[i].rect = {760,403,703,1000};}
		_menuItems.push_back(playButton[i]);
	}
	for (int i = 0; i < 7; i++)
	{	
		window.draw(xingqiu[i]);
	}
	window.display();
	//D¨¦finir la zone de rectangle de clic de souris
	//Quitter la plage de clics
	MenuItem exitButton;
	exitButton.rect.top = 0;
	exitButton.rect.left = 0;
	exitButton.rect.height =130 ;
	exitButton.rect.width =200;
	exitButton.action = Exit;
	//Placez la plage de clics ¨¤ l'int¨¦rieur du conteneur
	_menuItems.push_back(exitButton);
	return GetMenuResponse(window);
}

//D¨¦terminez si la position du clic de la souris se trouve ¨¤ l'int¨¦rieur de la zone rectangulaire pour renvoyer le param¨¨tre d'¨¦tat
MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	//L'it¨¦rateur parcourt la zone de clic stock¨¦e dans le conteneur de liste pour jugement
	std::list<MenuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
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
MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
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
