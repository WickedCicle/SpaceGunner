#include "Enemy.h"

void Enemy::set_direction(bool new_direction) {
	direction = new_direction;
}

int Enemy::get_direction() {
	return direction;
}

void Enemy::reverse_dir() {
	if (direction == direction::right) {
		direction = direction::left;
	}
	else {
		direction = direction::right;
	}
}