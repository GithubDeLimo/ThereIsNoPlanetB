#pragma once
#include "VisibleGameObject.h"

class GameObjectManager
{
public:	
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();

private:
	//Une carte de conteneur associative de paire cl¨¦-valeur, la cl¨¦ est le nom de l'objet et la valeur est le pointeur d'objet
	std::map<std::string, VisibleGameObject*> _gameObjects;

	//utilis¨¦ pour obtenir des fps
	sf::Clock clock;

	//Surcharger operator() pour obtenir un foncteur qui nettoie la m¨¦moire de l'objet VisibleGameObject
	//Les foncteurs, en termes simples, font r¨¦f¨¦rence ¨¤ des objets qui sont utilis¨¦s comme fonctions, dans ce cas GameObjectDeallocator()
	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string,VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};
};