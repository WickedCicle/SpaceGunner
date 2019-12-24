#include "KeyEvent.h"
#include "Menu.h"

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

void KeyState(Ship &Hero, vector<Bullet> &bullets, World &map, Timer &Move, Timer &Shoot, bool &EscapePressed) {
	if (GetKeyState('W') < 0) { // W
		MoveUp(Hero, map, Move);
	}
	if (GetKeyState('S') < 0) { // S
		MoveDown(Hero, map, Move);
	}
	if (GetKeyState(VK_ESCAPE) < 0) {
		EscapePressed = true;
		EscMenu();
	}
	if (GetKeyState(VK_SPACE) < 0) { // Пробел
		if (Shoot.get_time() > actions_cooldown::shoot_cooldown) {
			Hero.Fire(bullets);
			Shoot.reset_time();
		}
	}
}