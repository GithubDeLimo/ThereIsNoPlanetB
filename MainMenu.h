#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play,Mercure,Mars,Jupiter,Saturne,Vénus,Neptune,Uranus };
	//用结构体来存储矩形点击区域的属性参数信息
	struct MenuItem
	{
	public:
		//用来存储矩形区域范围的点的模板对象
		//一个点包含两个坐标值，两点形成一矩形区域
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
	//用来存储点击区域的容器
	std::list<MenuItem> _menuItems;
};
