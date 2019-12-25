#include "Actor.h"

#ifndef BULLET_H
#define BULLET_H

// класс описывающий пули
class Bullet : public Actor {
private:
	int damage = 1;	// переменная для урона
public:
	Bullet(int new_x, int new_y) : Actor(new_x, new_y) {};

	int get_damage();
	void set_damage(int new_damage);
};

#endif // !BULLET_H
