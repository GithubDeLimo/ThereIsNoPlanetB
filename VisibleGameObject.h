#pragma once
#include "stdafx.h"
class VisibleGameObject
{
public:
	VisibleGameObject();
	virtual ~VisibleGameObject();
	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow & window);
	virtual void Update(float elapsedTime);
	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition() const;
	virtual bool IsLoaded() const;
	//Obtenir la largeur de l'objet sprite
	virtual float GetWidth() const;
	//Obtenir la hauteur de l'objet sprite
	virtual float GetHeight() const;
	//Obtenir la zone rectangulaire de l'objet sprite
	virtual sf::Rect<float> GetBoundingRect() const;
	//D¨¦fini sur prot¨¦g¨¦ pour ¨ºtre appel¨¦ uniquement par les sous-classes h¨¦rit¨¦es
protected:
	sf::Sprite& GetSprite();
private:
	sf::Sprite  _sprite; //stocker des photos
	sf::Texture _image;  //lire l'image
	std::string _filename; //chemin de l'image
	bool _isLoaded; //Si la lecture a r¨¦ussi
};
