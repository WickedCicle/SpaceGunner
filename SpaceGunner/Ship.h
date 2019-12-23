#include "Actor.h"
#include <vector>
#include "Bullet.h"
#include <thread>

using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship : public Actor {
private:
	bool IsDead;
	int current_health;
	int max_health;
public:
	Ship(int new_x, int new_y, int new_health) : Actor(new_x, new_y) {
		IsDead = false;
		current_health = new_health;
		max_health = new_health;
	};

	int get_current_health();
	void set_current_health(int new_health);

	bool get_Is_dead();
	void DestroyShip();

	void ReceiveDamage(int damage);

	void Fire(vector<Bullet> &bullets);

	void Move(int x, int y);
};

#endif // !SHIP_H
