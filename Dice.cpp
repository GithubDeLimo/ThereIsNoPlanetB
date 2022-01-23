#include "Dice.h"
#include "SFML\System\Vector2.hpp"
Dice::Dice()
{
	//assert方法作用：括号里面的表达式必须返回true，若返回false则会出现系统错误
	Load("images/saizi.png");
	assert(IsLoaded());
	GetSprite().setPosition(812,568);	
}
Dice::~Dice()
{
}
Dice::DiceRect Dice::Show(sf::RenderWindow& window)
{
	window.draw(textNum);
	window.display();

	//骰子的点击范围
	diceClick diceBtn;		 
	diceBtn.rect = {804,564,763,1023}; //图片的范围
	diceBtn.action = Click;
	diceClick exitBtn;
	_dicerect.push_back(diceBtn);
	exitBtn.rect = { 0,0,563, 803};
	exitBtn.action = Nothing;
	_dicerect.push_back(exitBtn);
	return GetClickResponse(window);
}
//判断鼠标点击位置是否在矩形区域里面从而返回状态参数
Dice::DiceRect Dice::HandleClickes(int x, int y)
{
	//迭代器遍历list容器里面存放的点击区域以供判断
	std::list<diceClick>::iterator it;
	for (it = _dicerect.begin(); it != _dicerect.end(); it++)
	{
		sf::Rect<int> diceRect =(*it).rect;
		if (diceRect.width > y
			&& diceRect.top < y
			&& diceRect.left < x
			&& diceRect.height > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}
//根据鼠标动作来做出相应的响应
Dice::DiceRect  Dice::GetClickResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	srand((unsigned)time(NULL));
	//这里的42！=43可以理解为true
	while (42 != 43)
	{
		while (window.pollEvent(menuEvent))
		{   
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClickes(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
void Dice::diceNum(sf::RenderWindow& window)
{	
    if(n_Num>6)
      n_Num=1;
	if(!_font.loadFromFile("arial.ttf"))
		std::cout<<"cant not find font!";
	textNum.setFont(_font);
	textNum.setColor(sf::Color::Red);
	textNum.setCharacterSize(50);
	textNum.setPosition(GetSprite().getPosition().x+100,GetSprite().getPosition().y+50); //
	itoa(n_Num, s_Num, 10);	
	textNum.setString(s_Num);
	sf::sleep(sf::milliseconds(500));
	window.draw(textNum);
	window.display();
}