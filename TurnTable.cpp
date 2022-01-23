#include "StdAfx.h"
#include "TurnTable.h"
#include "Shop.h"
int TurnTable::Show(sf::RenderWindow& renderWindow)
{
	//创建texture对象来读取图片
	sf::Texture imagejian,imagePan;
	if (imagejian.loadFromFile("images/GreenArrowl.png") != true)
	{	std::cout<<"zhanpan image not found!";
		//return 1;
	}
	//创建sprite对象来存储图片
	sprite.setTexture(imagejian);
	sprite.setPosition(645,382);
	if(!imagePan.loadFromFile("images/zhanpanl.png"))
		std::cout<<"zhanpan image not found!";
	pan.setTexture(imagePan);
	pan.setPosition(0,0);
	sprite.setOrigin(21,360);
	//如果图片成功创建则将其显示到游戏窗口里
	renderWindow.draw(pan);
	renderWindow.draw(sprite);
	renderWindow.display();
	sf::Event event;
	sf::Clock t1;
	srand((unsigned)time(NULL));
	while (true)
	{
		//跟上一part一样，用renderWindow对象来监听鼠标动作事件
		while (renderWindow.pollEvent(event))
		{
			if ( _angle==0.f&&event.type == sf::Event::EventType::KeyPressed)    
			{
				_angle = std::rand() % 360;
				if(_angle>=0&&_angle<=30)
					n_cash=20;
				else if(_angle>30&&_angle<=60)
					n_cash=30;
				else if(_angle>60&&_angle<=90)
					n_cash=40;
				else if(_angle>90&&_angle<=120)
					n_cash=50;
				else if(_angle>120&&_angle<=150)
					n_cash=60;
				else if(_angle>150&&_angle<=180)
					n_cash=70;
				else if(_angle>180&&_angle<=210)
					n_cash=80;
				else if(_angle>210&&_angle<=240)
					n_cash=90;
				else if(_angle>240&&_angle<=270)
					n_cash=100;
				else if(_angle>270&&_angle<=300)
					n_cash=110;
				else if(_angle>300&&_angle<=330)
					n_cash=120;
				else if(_angle>330&&_angle<=360)
					n_cash=0;
				for (int i = 0; i < _angle+360; i += 2)
				{
					renderWindow.clear(sf::Color(255, 255, 255));
					turnaround(t1);
					renderWindow.draw(pan);
					renderWindow.draw(sprite);
					renderWindow.display();
				}
				z_cash=n_cash;
				CString getCash;
				getCash.Format(L"You get %d euro.",z_cash);
				if(MessageBoxW(NULL, getCash,L"Congratulations", MB_OK)==IDOK)
					return n_cash;
			}
			if (event.type == sf::Event::EventType:: MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{	
				return NULL;
			}
			
		}
	}
}
float TurnTable::turnaround(sf::Clock fsecond)
{
	sprite.setRotation(angle);
	angle+=2;
	if (angle > 360.0f)
		angle =0.0f;
	sf::sleep(sf::milliseconds(10));
	return sprite.getRotation();
}