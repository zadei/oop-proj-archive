#include <iostream>
#include <string>
#include "Entity.h"

Entity::Entity() {
hp = 100;
atk = 20;
name = "tobias";
}

/* these are not pure virtual as they are not implemented in chest
but are re-implemented in Player.h and Enemy.h */

void Entity::moveUp()
{

}
void Entity::moveDown()
{

}
void Entity::moveLeft()
{

}
void Entity::moveRight()
{

}
int Entity::getMove()
{
  return 0;
}

void Entity::takedmg(Entity* neil)
{

}
int Entity::get_Health()
{
    return hp;
}
void Entity::set_Health(int s_health)
{
    hp = s_health;
}
int Entity::get_Atk()
{
    return atk;
}
void Entity::set_Atk(int s_atk)
{
    atk = s_atk;
}

// default destructor
Entity::~Entity()
{

}
