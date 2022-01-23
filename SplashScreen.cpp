#include "StdAfx.h"
#include "SplashScreen.h"
void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	//Cr¨¦er un objet de texture pour lire l'image
	sf::Texture image;
	if (image.loadFromFile("images/InterstellarTravel.png") != true)
	{
		return;
	}
	//Cr¨¦er des objets sprite pour stocker des images
	sf::Sprite sprite(image);
	//Si l'image est cr¨¦¨¦e avec succ¨¨s, affichez-la dans la fen¨ºtre du jeu
	renderWindow.draw(sprite);
	renderWindow.display();
	sf::Event event;
	while (true)
	{
		//Comme la partie pr¨¦c¨¦dente, utilisez l'objet renderWindow pour ¨¦couter les ¨¦v¨¦nements d'action de la souris
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}
}