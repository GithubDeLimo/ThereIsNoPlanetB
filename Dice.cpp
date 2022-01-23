#include "Dice.h"
#include "SFML\System\Vector2.hpp"
Dice::Dice()
{
	//assert�������ã���������ı��ʽ���뷵��true��������false������ϵͳ����
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

	//���ӵĵ����Χ
	diceClick diceBtn;		 
	diceBtn.rect = {804,564,763,1023}; //ͼƬ�ķ�Χ
	diceBtn.action = Click;
	diceClick exitBtn;
	_dicerect.push_back(diceBtn);
	exitBtn.rect = { 0,0,563, 803};
	exitBtn.action = Nothing;
	_dicerect.push_back(exitBtn);
	return GetClickResponse(window);
}
//�ж������λ���Ƿ��ھ�����������Ӷ�����״̬����
Dice::DiceRect Dice::HandleClickes(int x, int y)
{
	//����������list���������ŵĵ�������Թ��ж�
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
//������궯����������Ӧ����Ӧ
Dice::DiceRect  Dice::GetClickResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	srand((unsigned)time(NULL));
	//�����42��=43�������Ϊtrue
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