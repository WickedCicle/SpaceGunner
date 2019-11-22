#include "Ship.h"
#include "World.h"

int Ship::get_current_health() {
	return current_health;
}

void Ship::set_current_health(int new_health) {
	current_health = new_health;
}

bool Ship::get_Is_dead() {
	return IsDead;
}

void Ship::DestroyShip() {
	IsDead = true;
}

void Ship::Fire(vector<Bullet> &bullets) {
	bullets.push_back(Bullet(get_x_pos() + 1, get_y_pos()));
}

void Ship::ReceiveDamage(int damage) {
	current_health -= damage;
}

void Ship::Move(int x, int y) {
	set_x_pos(get_x_pos() + x);
	set_y_pos(get_y_pos() + y);
}