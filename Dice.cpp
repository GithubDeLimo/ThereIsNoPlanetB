#include "Dice.h"
#include "SFML\System\Vector2.hpp"
Dice::Dice()
{
	//La fonction de la m¨¦thode assert : l'expression entre parenth¨¨ses doit retourner vrai, si elle retourne faux, une erreur syst¨¨me se produira
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

	//La plage de clics des d¨¦s
	diceClick diceBtn;		 
	diceBtn.rect = {804,564,763,1023}; //gamme de photos
	diceBtn.action = Click;
	diceClick exitBtn;
	_dicerect.push_back(diceBtn);
	exitBtn.rect = { 0,0,563, 803};
	exitBtn.action = Nothing;
	_dicerect.push_back(exitBtn);
	return GetClickResponse(window);
}
//D¨¦terminez si la position du clic de la souris se trouve ¨¤ l'int¨¦rieur de la zone rectangulaire pour renvoyer le param¨¨tre d'¨¦tat
Dice::DiceRect Dice::HandleClickes(int x, int y)
{
	//L'it¨¦rateur parcourt la zone de clic stock¨¦e dans le conteneur de liste pour jugement
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
//R¨¦pondre aux actions de la souris
Dice::DiceRect  Dice::GetClickResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	srand((unsigned)time(NULL));
	//42 ici! =43 peut ¨ºtre compris comme vrai
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