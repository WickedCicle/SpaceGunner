#include "Ship.h"
#include "World.h"
#include "Timer.h"

#ifndef KEY_H
#define KEY_H

enum actions_cooldown {
	shoot_cooldown = 250,
	move_cooldown = 100
};

void MoveUp(Ship &Hero, World &map, Timer &Move);
void MoveDown(Ship &Hero, World &map, Timer &Move);
void MoveLeft(Ship &Hero, World &map, Timer &Move);
void MoveRight(Ship &Hero, World &map, Timer &Move);

void KeyState(Ship &Hero, vector<Bullet> &bullets, World &map, Timer &Move, Timer &Shoot);

#endif // !KEY_H
