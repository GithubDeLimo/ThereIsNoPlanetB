#pragma once
#include "VisibleGameObject.h"
#include "Game.h"
#include "SFML\Audio.hpp"
// �̳���VisibleGameObject
class Planet :public VisibleGameObject
{
public:
	Planet();
	virtual ~Planet();
	void Planet::Update(float elapsedTime);
	struct Map
	{
	public:
		int x; //���������ͼ�ϵĵ㣬x
		int y;  //���y����
	}maps[8];
	int i=3;int j=-1;
	sf::Vector2f starPos = {-50,-50};
	float _elapsedTimeSinceStart;  //��Ϸ��ʱ��
private:
	float _velocity;  //�ٶ�
	int px=0,py=0;
	float LinearVelocityX(int x); //ˮƽ���ٶ�
	float LinearVelocityY(int y);  //��ֱ���ٶ�
	
};
