#include "stdafx.h"
#include "GameObjectManager.h"
GameObjectManager::GameObjectManager()
{	
}
GameObjectManager::~GameObjectManager()
{
	//Lib¨¨re la m¨¦moire de tous les objets VisibleGameObject dans le conteneur de carte
	std::for_each(_gameObjects.begin(),_gameObjects.end(),GameObjectDeallocator());
}
void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	//Ajouter le nom de l'objet et l'objet au conteneur via une paire
	_gameObjects.insert(std::pair<std::string,VisibleGameObject*>(name,gameObject));
}
void GameObjectManager::Remove(std::string name)
{
	//Utilisez la m¨¦thode find du conteneur pour trouver l'objet, s'il est trouv¨¦, lib¨¦rez sa m¨¦moire et effacez le nom de la cl¨¦
	std::map<std::string, VisibleGameObject*>::iterator results = _gameObjects.find(name);
	if(results != _gameObjects.end() )
	{
		delete results->second;
		_gameObjects.erase(results);
	}
}
VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	//La m¨¦thode find trouve un objet et renvoie l'objet s'il est trouv¨¦
	std::map<std::string, VisibleGameObject*>::const_iterator results = _gameObjects.find(name);
	if(results == _gameObjects.end() )
		return NULL;
	return results->second;
}
int GameObjectManager::GetObjectCount() const
{
	return _gameObjects.size();
}
void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	//Ajouter des objets ¨¤ la sc¨¨ne de jeu
	std::map<std::string,VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	while(itr != _gameObjects.end())
	{
		itr->second->Draw(renderWindow);
		itr++;
	}
}
//Appelez la m¨¦thode de mise ¨¤ jour respective de l'objet pour le mettre ¨¤ jour, timeDelta peut ¨ºtre consid¨¦r¨¦ comme fps
void GameObjectManager::UpdateAll()
{
	std::map<std::string,VisibleGameObject*>::const_iterator itr = _gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while(itr != _gameObjects.end())
	{
		itr->second->Update(timeDelta);
		itr++;
	}
}