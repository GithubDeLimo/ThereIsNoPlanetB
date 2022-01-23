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
	//�ýṹ�����洢���ε����������Բ�����Ϣ
	struct ShopMenuItem
	{
	public:
		//�����洢��������Χ�ĵ��ģ�����
		//һ���������������ֵ�������γ�һ��������
		sf::Rect<int> rect;
		ShopMenuResult action;
	};
	//sf::Sprite Something[7];
	//sf::Texture imgSomething[7];
	char SomethingName[64];
	sf::Sprite shopSpr;
	int Remainingcash(int m_cash);	 //��ʾʣ���ֽ�
	ShopMenuResult Show(sf::RenderWindow& window);
private:
	ShopMenuResult GetShopMenuResponse(sf::RenderWindow& window);
	ShopMenuResult HandleClick(int x, int y);
	//�����洢������������
	std::list<ShopMenuItem> _shopmenuItems;
};
static sf::Text textSc,textSy;

