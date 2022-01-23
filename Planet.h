#pragma once
#include "VisibleGameObject.h"
#include "Game.h"
#include "SFML\Audio.hpp"
// 继承自VisibleGameObject
class Planet :public VisibleGameObject
{
public:
	Planet();
	virtual ~Planet();
	void Planet::Update(float elapsedTime);
	struct Map
	{
	public:
		int x; //定义星球地图上的点，x
		int y;  //点的y坐标
	}maps[8];
	int i=3;int j=-1;
	sf::Vector2f starPos = {-50,-50};
	float _elapsedTimeSinceStart;  //游戏总时间
private:
	float _velocity;  //速度
	int px=0,py=0;
	float LinearVelocityX(int x); //水平线速度
	float LinearVelocityY(int y);  //垂直线速度
	
};
