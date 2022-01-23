#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.h"
#include "VisibleGameObject.h"
#include "Planet.h"
#include "End.h"

class Game
{
public:
	static void Start();
	const static GameObjectManager& GetGameObjectManager();
	static sf::RenderWindow& GetWindow();
	const static sf::Event& GetInput();
	static void Remainingcash();
	
	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;
	
private:
	static bool IsExiting();
	static void GameLoop();
	static void ShowSplashScreen();
	static int ShowTurnTable();
	static void Showshop();
	static void ShowMenu();
	static void ShowEnd();
	
	//用枚举类型来代替常量表示游戏状态
	enum GameState {
		Uninitialized, ShowingSplash, Paused,STurnTable,ShowShop,
		ShowingMenu, Playing, Exiting,ShowingEnd
	};
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
};
static sf::Text textSce,textSye;
static sf::Font font_;  
static char s_cash[3];