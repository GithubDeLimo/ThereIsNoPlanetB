#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class MainMenu
{
public:
	enum MenuResult { Nothing, Exit, Play,Mercure,Mars,Jupiter,Saturne,V��nus,Neptune,Uranus };
	//�ýṹ�����洢���ε����������Բ�����Ϣ
	struct MenuItem
	{
	public:
		//�����洢��������Χ�ĵ��ģ�����
		//һ���������������ֵ�������γ�һ��������
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
	//�����洢������������
	std::list<MenuItem> _menuItems;
};
