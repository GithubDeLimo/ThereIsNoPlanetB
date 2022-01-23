#include "Planet.h"
#include "stdafx.h"
Planet::Planet() :
	_velocity(1.0f),
	_elapsedTimeSinceStart(0.0f)
{
	//La fonction de la m¨¦thode assert : l'expression entre parenth¨¨ses doit retourner vrai, si elle retourne faux, une erreur syst¨¨me se produira
	Load("images/spaceMans.png");
	assert(IsLoaded());
	GetSprite().setPosition(starPos);	
	GetSprite().setOrigin(-20, 105);
	GetSprite().setScale(0.4f,0.4f);
	
	
}
Planet::~Planet()
{
}
void Planet::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;
	// Les personnages marchent selon un certain temps
	if (_elapsedTimeSinceStart < 0.6f)
	{
		switch (i)
		{
		case 1:
		{
			switch (j)
			{
			case 0:	  starPos = { -50,450 };GetSprite().setPosition(starPos); break;
	        case 1:case 2:case 3:case 4:
				LinearVelocityX(9);break;
			case 5:
				LinearVelocityY(-9);break;
			case 6:case 7:
				LinearVelocityX(-9);break;
			}
			break;
		default:

			break;
		}
		case 2:
			switch (j)
			{
			case 0:	  starPos={ 303,535 };GetSprite().setPosition(starPos); break;
			case 1:case 2:case 3:
				LinearVelocityX(9);break;
			case 4:case 5:
				LinearVelocityY(-9);break;
			case 6:case 7:
				LinearVelocityX(-9);break;
			default:
				break;
			}
			break;
		case 3:				 //Jupiter 
			switch (j)
			{
			case 0:	  starPos={ -30,535 };GetSprite().setPosition(starPos); break;
			case 1:case 2:case 3:case 5:
			case 7:
				LinearVelocityX(9);break;
			case 4:
				LinearVelocityY(-9);break;
			case 6: LinearVelocityY(9);break;
			default:
				break;
			}
			break;
		case 4:				 //Saturne 
			{switch (j)
			{
			case 0:	  starPos = { 200,80 }; GetSprite().setPosition(starPos); break;
			case 1:case 2:case 3:case 6: case 7:
				LinearVelocityY(9); break;
			case 4:case 5:
				LinearVelocityX(9); break;
			default:
				break;
			}
			break;
			}
		case 5:				 //V¨¦nus 
			switch (j)
			{
			case 0:	  starPos={ -35,400 };GetSprite().setPosition(starPos); break;
			case 1:case 2:case 3:case 5:case 6: case 7:
				LinearVelocityX(9);break;
			case 4:
				LinearVelocityY(-9);break;
			default:
				break;
			}
			break;
		case 6:				 //Neptune 
			switch (j)
			{
			case 0:	  starPos={ -5,650 };GetSprite().setPosition(starPos); break;
			case 2:case 3:
				LinearVelocityY(-9);break;
			case 1: case 4:	case 7:
				LinearVelocityX(9);break;
			case 5:case 6: 	LinearVelocityY(9);break;
			default:
				break;
			}
			break;
		case 7:				 //Uranus 
			switch (j)
			{
			case 0:	  starPos={ -45,515 };GetSprite().setPosition(starPos); break;
			case 1:case 2:case 3: case 4:case 5:case 6:	case 7:
				LinearVelocityX(9);break;
			default:
				break;
			}
			break;
		}
	}
}
float Planet::LinearVelocityX(int x)
{
	px=GetSprite().getPosition().x;
	px+=x;
	sf::sleep(sf::milliseconds(30));
	if ( px > 1020)
	{
		px = 1020;
	}
	if( px < -60)
	{	
		px =-60;
	}
	GetSprite().setPosition(px,GetSprite().getPosition().y);
	return GetSprite().getPosition().x;
}
float Planet::LinearVelocityY(int y)
{
	py=GetSprite().getPosition().y;
	py+=y;
	sf::sleep(sf::milliseconds(30));
	if(py>760)
		py=760;
	if(py<10)
		py=10;
	GetSprite().setPosition(GetSprite().getPosition().x,py);
	return GetSprite().getPosition().y;
}
