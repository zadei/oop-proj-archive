// defining parent class for all objects
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

// initiating class entity
class Entity {
public:
  // variables shared between all child classes
  int hp, atk;
  string name;

  Entity();
  // entity movement and interactive function declaration
  virtual void moveUp();
  virtual void moveDown();
  virtual void moveLeft();
  virtual void moveRight();
  virtual int getMove();
  virtual void takedmg(Entity* neil);
  virtual int get_Health();
  virtual void set_Health(int s_health);
  virtual int get_Atk();
  virtual void set_Atk(int s_atk);

// pure virtual void functions
  virtual string get_Name()=0;
  virtual void display()=0;
  ~Entity();
};

// end if
#endif
