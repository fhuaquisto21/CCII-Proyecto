#ifndef GUNWEAPON_H
#define GUNWEAPON_H

#include "./Weapon.h"

class GunWeapon: public Weapon
{
private:
public:
    GunWeapon();
    ~GunWeapon();
    void draw(sf::RenderWindow *);
    void events(sf::Event *);
};

#include "./Gun.Weapon.cpp"

#endif



