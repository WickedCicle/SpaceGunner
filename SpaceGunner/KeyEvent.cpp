#include "KeyEvent.h"

void MoveUp(Ship &Hero, World &map, Timer &Move) {
	if (Hero.get_y_pos() > 2 && Move.get_time() > actions_cooldown::move_cooldown) {
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::space);
		Hero.Move(0, -1);
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::hero);
		Move.reset_time();
	}
}

void MoveDown(Ship &Hero, World &map, Timer &Move) {
	if (Hero.get_y_pos() < map.get_width() - 3 && Move.get_time() > actions_cooldown::move_cooldown) {
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::space);
		Hero.Move(0, 1);
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::hero);
		Move.reset_time();
	}
}

void MoveLeft(Ship &Hero, World &map, Timer &Move) {
	if (Hero.get_x_pos() > 0 && Move.get_time() > actions_cooldown::move_cooldown) {
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::space);
		Hero.Move(-1, 0);
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::hero);
		Move.reset_time();
	}
}

void MoveRight(Ship &Hero, World &map, Timer &Move) {
	if (Hero.get_x_pos() < 20 && Move.get_time() > actions_cooldown::move_cooldown) {
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::space);
		Hero.Move(1, 0);
		map.SetMapSymbol(Hero.get_x_pos(), Hero.get_y_pos(), map_symbols::hero);
		Move.reset_time();
	}
}

void KeyState(Ship &Hero, vector<Bullet> &bullets, World &map, Timer &Move, Timer &Shoot) {
	if (GetAsyncKeyState('W') == -32768) { // W
		MoveUp(Hero, map, Move);
	}
	if (GetAsyncKeyState('S') == -32768) { // S
		MoveDown(Hero, map, Move);
	}
	if (GetAsyncKeyState('A') == -32768) { // A
		MoveLeft(Hero, map, Move);
	}
	if (GetAsyncKeyState('D') == -32768) { // D
		MoveRight(Hero, map, Move);
	}
	if (GetAsyncKeyState(VK_SPACE) == -32768) { // Пробел
		if (Shoot.get_time() > actions_cooldown::shoot_cooldown) {
			Hero.Fire(bullets);
			Shoot.reset_time();
		}
	}
}