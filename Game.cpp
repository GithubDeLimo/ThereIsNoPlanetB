#include "stdafx.h"
#include "Game.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "TurnTable.h"
#include "Dice.h"

#include "Shop.h"
#include "Windows.h"
#include "tchar.h"
using namespace std;
int cash=0;
Dice *dice=new Dice();
int j=0,n=0,k=0;
bool flag = true;
int together=0;
MainMenu mainMenu;
sf::Texture imgMap;
Planet *planet=new Planet();
void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	//D¨¦finissez les param¨¨tres de la fen¨ºtre, taille 1024, 768, titre "There is no planet B!"
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "There is no planet B!"); 	
	_gameObjectManager.Add("man", planet);
	_gameObjectManager.Add("dice", dice);
	_gameState = Game::ShowingSplash; 
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("music/music.wav"))
	{
		std::cout << "music file not found" << std::endl;
		return;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setLoop(true);
	sound.play(); //jouer de la musique
	//La boucle de jeu, lorsque l'¨¦tat du jeu est Exiting, quittez le jeu
	while (!IsExiting())
	{
		GameLoop();
	}
	_mainWindow.close();
}
const GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}
bool Game::IsExiting()
{
	if (_gameState == Game::Exiting)
		return true;
	else
		return false;
}
void Game::GameLoop()
{
	sf::Event currentEvent;
	//Obtenir le message de la file d'attente des messages
	_mainWindow.pollEvent(currentEvent);
	switch (_gameState)
	{
	case Game::ShowingEnd:
	{
		ShowEnd();
		break;
	}
	case Game::ShowingSplash:
	{
		ShowSplashScreen();
		break;
	}
	case Game::STurnTable:
	{
		_mainWindow.clear(sf::Color(255, 255, 255));
		ShowTurnTable();
		break;
	}
	case Game::ShowShop:
	{
		_mainWindow.clear(sf::Color(255, 255, 255));
		Showshop();
		break;
	}
	case Game::ShowingMenu:
	{
		_mainWindow.clear(sf::Color(0, 0, 0));
		ShowMenu();
		break;
	}
	case Game::Playing:
	{
		
		sf::Texture background;
		sf::Sprite sbackgroud;
		if(!background.loadFromFile("images/map.png"))
			return;
		sbackgroud.setTexture(imgMap);
		//Remplir l'¨¦cran de jeu de noir
		_mainWindow.clear(sf::Color(0, 0, 0));
		_mainWindow.setFramerateLimit(100);
		_gameObjectManager.UpdateAll();
		_mainWindow.draw(sbackgroud);
		 Remainingcash();
		_gameObjectManager.DrawAll(_mainWindow);
		_mainWindow.display();
		if (currentEvent.type == sf::Event::Closed)
		{
			_gameState = Game::Exiting;
		}
			int nn=0;	
			if (currentEvent.type == sf::Event::KeyPressed&&flag == true)//
			{
				planet->_elapsedTimeSinceStart = 0;
				planet->Update(0);
				
   				j++;
				planet->j+=1;
				if (j >=n)
					flag = false;
				if(planet->j>=8)
				{
					planet->j=-1;
					if (MessageBoxW(NULL, L"Ask if you will travel to other planets for a week?", L"The week's trip is over!", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
						_gameState = Game::ShowingEnd;
					else
						_gameState = Game::ShowShop;
				}
			}
			if (currentEvent.type == sf::Event::MouseButtonPressed)//KeyPressed
			{
				if(cash<10)
				{
					MessageBoxW(NULL, L"You don't have enough cash to continue your journey. Go home now!", L"Report!", MB_OK);
					_gameState = Game::ShowingEnd; 
				}
				cash=cash-10;
				
				srand((unsigned)time(NULL));
				Dice::DiceRect dicerect = dice->Show(_mainWindow);
				switch (dicerect)
				{
				case Dice::Exit:
					_gameState = Exiting;  //Quitter la page d'achat
					break;
				case Dice::Click:
				{ 
				nn = std::rand() % 6 + 1;
				n = nn;
				dice->n_Num=nn;
				dice->diceNum(_mainWindow);
				sf::sleep(sf::milliseconds(900));
				j = 0;
				flag = true;
			}
				break;
			}
			if (currentEvent.key.code == sf::Keyboard::Escape)
				ShowMenu();
		}
	}  
		break;
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);	   //page de d¨¦marrage
	_gameState = Game::STurnTable;
}
int Game::ShowTurnTable()
{
	TurnTable turnTable;
	turnTable.Show(_mainWindow);	  //page de carrousel
	cash=turnTable.z_cash;
	_gameState = Game::ShowShop; //entrer dans le magasin
	return cash;
}
void Game::Showshop()
{	
	Shop shopMenu;
    shopMenu.Remainingcash(cash);	   //page du magasin
    Shop::ShopMenuResult shopresult=shopMenu.Show(_mainWindow);
	switch (shopresult)
	{
	case Shop::Exit:
		_gameState = ShowingMenu;  //Cliquez sur une section vide dans le magasin pour quitter la page d'achat
		break;
	case Shop::sunBuy:
		 cash=cash-2;
		 mainMenu.sun=1;
		 shopMenu.Remainingcash(cash); //acheter quelque chose, moins le prix correspondant
		break;
	case Shop::foodBuy:
		cash=cash-3;
		mainMenu.food=1;
		shopMenu.Remainingcash(cash);
		break;
	case Shop::waterBuy:
		cash=cash-5;
		mainMenu.water=1;
		shopMenu.Remainingcash(cash);
		break;
	case Shop::gravityBuy:
		cash=cash-5;
		mainMenu.gravity=1;
		shopMenu.Remainingcash(cash);
		break;
	case Shop::tempBuy:
		cash=cash-10;
		mainMenu.temperatures=1;
		shopMenu.Remainingcash(cash);
		break;
	case Shop::landBuy:
		cash=cash-15;
		mainMenu.land=1;
		shopMenu.Remainingcash(cash);
		break;
	case Shop::oxygenBuy:
		cash=cash-20;
		mainMenu.oxygen=1;
		shopMenu.Remainingcash(cash);
		break;
	default:
		shopMenu.Remainingcash(cash);
		break;
	}
	if (cash <= 0)
	{
		cash=0;
		MessageBoxW(NULL, L"Not sufficient funds,Please RestartGame", L"Attention", MB_TASKMODAL);
		_gameState = ShowingEnd;
	}
}
void Game::ShowMenu()
{
		  //Page de s¨¦lection des sept plan¨¨tes
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	 sf::Sprite sp_bg;
	switch (result)
	{
	case MainMenu::Exit:
		_gameState = Playing;  //Exiting;	   ShowShop
		break;
	case MainMenu::Mercure:
		mainMenu.land=1;mainMenu.sun=1;
		if(!imgMap.loadFromFile("images/mer_map.png"))
			return;
		planet->i=1;
		planet->starPos = { -40,435 }; //465
		break;
	case MainMenu::Mars:
		mainMenu.land=1;mainMenu.sun=1;mainMenu.water=1;mainMenu.oxygen=1;
		if(!imgMap.loadFromFile("images/mar_map.png"))
			return;
		planet->i=2;
		planet->starPos={ 453,505 };
		break;
	case MainMenu::V¨¦nus:
		mainMenu.land=1;mainMenu.sun=1;mainMenu.gravity=1;
		if(!imgMap.loadFromFile("images/ver_map.png"))
			return;
		planet->i=5;
		break;
	case MainMenu::Saturne:
		mainMenu.water=1;mainMenu.sun=1;
		if(!imgMap.loadFromFile("images/sat_map.png"))
			return;
		planet->i=4;
		planet->starPos={ 330,160 };
		break;
	case MainMenu::Jupiter:
		mainMenu.sun = 1;
		if(!imgMap.loadFromFile("images/jup_map.png"))
			return;
		planet->i=3;
		break;
	case MainMenu::Neptune:
		planet->i=6;
		if(!imgMap.loadFromFile("images/nep_map.png"))
			return;
		break;
	case MainMenu::Uranus:
		mainMenu.gravity=1;mainMenu.sun=1;mainMenu.oxygen=1;mainMenu.temperatures=1;
		if(!imgMap.loadFromFile("images/ura_map.png"))
			return;
		planet->i=7;
		break;
	}
		if(mainMenu.sun==0)
			MessageBoxW(NULL, L"You lack sun resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.water==0)
			MessageBoxW(NULL, L"You lack water resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.food==0)
			MessageBoxW(NULL, L"You lack food resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.land==0)
			MessageBoxW(NULL, L"You lack land resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.oxygen==0)
			MessageBoxW(NULL, L"You lack oxygen resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.temperatures==0)
			MessageBoxW(NULL, L"You lack temperatures resources!", L"Attention", MB_TASKMODAL);
		if(mainMenu.gravity==0)
			MessageBoxW(NULL, L"You lack gravity resources!", L"Attention", MB_TASKMODAL);

		if (mainMenu.gravity == 1 && mainMenu.sun == 1 && mainMenu.water == 1 && mainMenu.food == 1
			&& mainMenu.oxygen == 1 && mainMenu.temperatures == 1 && mainMenu.land == 1)
		{
			_gameState = Playing;
			}
		mainMenu.sun=0;mainMenu.water=0;mainMenu.food=0;mainMenu.temperatures=0;mainMenu.gravity=0;mainMenu.land=0;mainMenu.oxygen=0;

}
void Game::ShowEnd()
{
	End end;
	end.Show(_mainWindow);
}
sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}
//Cr¨¦ez une variable de type Event, prenez le message de la file d'attente des messages du syst¨¨me et placez-le dans la variable et retournez
const sf::Event& Game::GetInput()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}
void Game::Remainingcash()
{
	if(!font_.loadFromFile("arial.ttf"))
		std::cout<<"cant not find font!";
	textSce.setFont(font_);
	textSce.setColor(sf::Color::Red);
	textSce.setCharacterSize(20);
	textSce.setPosition(120,25);
	textSye.setFont(font_);
	textSye.setColor(sf::Color::Red);
	textSye.setCharacterSize(20);
	textSye.setPosition(0,0);
	textSye.setString("Please keypress space to GameStart!\nRemainCash:");
	itoa(cash, s_cash, 10);
	textSce.setString(s_cash);
	_mainWindow.draw(textSye);
	_mainWindow.draw(textSce);
//	_mainWindow.display();
	//return m_cash;
}
//Vous devez d¨¦clarer manuellement les variables statiques ici, sinon le compilateur signalera une erreur
Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;