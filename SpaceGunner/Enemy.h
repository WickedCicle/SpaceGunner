#include "Ship.h"

#ifndef ENEMY_H
#define ENEMY_H

enum direction {
	left = 0,
	right = 1
};

class Enemy : public Ship {
private:
	bool direction = direction::right;
public:
	Enemy(int new_x, int new_y, int new_health) : Ship(new_x, new_y, new_health) {};
	void set_direction(bool direction);
	int get_direction();
	void reverse_dir();
};

#endif // 
