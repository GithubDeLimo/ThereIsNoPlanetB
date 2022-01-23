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
	//用结构体来存储矩形点击区域的属性参数信息
	struct ShopMenuItem
	{
	public:
		//用来存储矩形区域范围的点的模板对象
		//一个点包含两个坐标值，两点形成一矩形区域
		sf::Rect<int> rect;
		ShopMenuResult action;
	};
	//sf::Sprite Something[7];
	//sf::Texture imgSomething[7];
	char SomethingName[64];
	sf::Sprite shopSpr;
	int Remainingcash(int m_cash);	 //显示剩余现金
	ShopMenuResult Show(sf::RenderWindow& window);
private:
	ShopMenuResult GetShopMenuResponse(sf::RenderWindow& window);
	ShopMenuResult HandleClick(int x, int y);
	//用来存储点击区域的容器
	std::list<ShopMenuItem> _shopmenuItems;
};
static sf::Text textSc,textSy;

