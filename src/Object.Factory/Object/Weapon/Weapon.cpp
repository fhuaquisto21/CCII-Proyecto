#include <iostream>
#include <math.h>
#include "./Weapon.h"


Weapon::Weapon(std::string _name, float _speed) : Object(_name, "Weapon")
{
    this->speed = _speed;
    this->munition = 5;
    this->translate = new sf::Vector2f;

    this->playerCenter = new sf::Vector2f;
    this->mousePosWindow = new sf::Vector2f;
    this->aimDir = new sf::Vector2f;
    this->aimDirNorm = new sf::Vector2f;

}

Weapon::~Weapon() {}

void Weapon::move(sf::Event *_event)
{
    if (this->translate->x != 0.f || this->translate->y != 0.f)
        *this->translate /= std::sqrt(2.f);

    this->getSprite()->move(*this->translate);
}

void Weapon::events(sf::Event *_event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->translate->y -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->translate->y += this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->translate->x += this->speed;
    std::cout << this->translate->x << " " << this->translate->y << std::endl;   
}

void Weapon::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
    this->move(new sf::Event);
    this->disparar(_window);
    
}
 void Weapon::disparar(sf::RenderWindow * _window) {
    _window->setFramerateLimit(60);
    int spawnCounter = 10;

    float a = sqrt(pow(aimDir->x, 2) + pow(aimDir->y, 2));
	*this->playerCenter = sf::Vector2f(getSprite()->getPosition());
	*this->mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(*_window));
	*this->aimDir = *this->mousePosWindow - *this->playerCenter;
	*this->aimDirNorm = *this->aimDir /  a;

	float PI = 3.14159265f;
	float deg = atan2(aimDirNorm->y, aimDirNorm->x) * 180 / PI;
	getSprite()->setRotation(deg + 90);

	//Set Final Rotation of Ship
	std::cout << deg << "\n";

    if (spawnCounter < 20) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			b1.shape.setPosition(*playerCenter);
			b1.currVelocity = *aimDirNorm * b1.maxSpeed;

			bullets.push_back(Bullet(b1));
		}
        		
        for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].shape.move(bullets[i].currVelocity);

			//Out of bounds
			if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > _window->getSize().x
				|| bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > _window->getSize().y)
			{
				bullets.erase(bullets.begin() + i);
            }
        }
    }

    for (size_t i = 0; i < bullets.size(); i++)
	{
		_window->draw(bullets[i].shape);
	}

		
 }

 

