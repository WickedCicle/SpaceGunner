#include "Actor.h"
#include <vector>
#include "Bullet.h"
#include <thread>

using namespace std;

#ifndef SHIP_H
#define SHIP_H

class Ship : public Actor {
private:
	bool IsDead; // переменная хранит состояние корабля
	int current_health; // хранит текущее количество здоровья
	int max_health; // хранит максимальное количество здоровья
public:
	Ship(int new_x, int new_y, int new_health) : Actor(new_x, new_y) {
		IsDead = false;
		current_health = new_health;
		max_health = new_health;
	};

	int get_current_health();
	void set_current_health(int new_health);

	bool get_Is_dead();
	void DestroyShip(); // устанавливает значение поля IsDead на True

	void ReceiveDamage(int damage); // уменьшает текущее здоровья на величину damage

	void Fire(vector<Bullet> &bullets); // производит выстрел

	void Move(int x, int y); // перемещает корабль на координаты x,y, относительно текущего положения
};

#endif // !SHIP_H
