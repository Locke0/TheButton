#pragma once
#include <SFML/Graphics.hpp>

class Buttons
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Buttons();

	virtual void initButton();


};


class GreenButtons : public Buttons
{
public:
	void initButton() override;

};