#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include "./../Object.h"



class Bullet
{
public:
	sf::CircleShape shape;
	sf::Vector2f currVelocity;
	float maxSpeed;

	Bullet(float radius = 6.f)
		: currVelocity(0.f, 0.f), maxSpeed(5.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(sf::Color::Blue);
	}
};


class Weapon : public Object
{
private:
    float speed;
    int munition;
    sf::Vector2f *translate;

    sf::Vector2f *playerCenter;
    sf::Vector2f *mousePosWindow;
    sf::Vector2f *aimDir;
    sf::Vector2f *aimDirNorm;  

    Bullet b1;
    std::vector<Bullet> bullets;
    
    sf::RectangleShape *enemy;     

public:
    Weapon(std::string, float);
    ~Weapon();
    void move(sf::Event *);
    virtual void events(sf::Event *);
    virtual void draw(sf::RenderWindow *);
    virtual void disparar(sf::RenderWindow *);
    void collisions();
};


#include "./Weapon.cpp"

#endif
