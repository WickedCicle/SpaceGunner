#include "World.h"

World::World(int new_length, int new_width) {
	length = new_length;
	width = new_width;

	map = new wchar_t*[width];
	for (int i = 0; i < width; i++) {
		map[i] = new wchar_t[length + 1];
	}
}

int World::get_length() {
	return length;
}

int World::get_width(){
	return width;
}

void World::CreateMap(Ship Hero) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < length; j++) {
			map[i][j] = map_symbols::border;
		}
	}

	for (int i = 2; i < width - 2; i++) {
		for (int j = 0; j < length; j++) {
			if (j == Hero.get_x_pos() && i == Hero.get_y_pos()) {
				map[i][j] = map_symbols::hero;
			}
			else {
				map[i][j] = map_symbols::space;
			}
		}
	}

	for (int i = width - 2; i < width; i++) {
		for (int j = 0; j < length; j++) {
			map[i][j] = map_symbols::border;
		}
	}

	for (int i = 0; i < width; i++) {
		for (int j = length; j < length + 1; j++) {
			map[i][j] = L'\0';
		}
	}

	SetCurPos(0, 0);
	for (int i = 0; i < width; i++) {
		wprintf_s(L"%s\n", map[i]);
	}

	/*for (int i = 0; i < width; i++) {
		for (int j = 0; j < length; j++) {
			wcout << map[i][j];
		}
		wcout << endl;
	}*/
}

void World::DrawBullets(vector<Bullet> &bullets) {
	int count_bullets = bullets.size();

	for (int i = 0; i < count_bullets; i++) {
		if (map[bullets[i].get_y_pos()][bullets[i].get_x_pos() - 1] == map_symbols::hero_bullet) {
			map[bullets[i].get_y_pos()][bullets[i].get_x_pos() - 1] = map_symbols::space;
		}
		map[bullets[i].get_y_pos()][bullets[i].get_x_pos()] = map_symbols::hero_bullet;
	}
}

void World::MoveBullets(vector<Bullet> &bullets) {
	int count_bullets = bullets.size();

	for (int i = 0; i < count_bullets; i++) {
		bullets[i].set_x_pos(bullets[i].get_x_pos() + 1);
	}
}

void World::SetMapSymbol(int x, int y, wchar_t symbol) {
	map[y][x] = symbol;
}

/*wchar_t World::GetMapSymbol(int x, int y) {
	return map[y][x];
}*/

void World::bullet_out_of_range(vector<Bullet> &bullets) {
	int count_bullets = bullets.size();

	for (int i = count_bullets - 1; i >= 0; i--) {
		if (bullets[i].get_x_pos() == length) {
			SetMapSymbol(bullets[i].get_x_pos() - 1, bullets[i].get_y_pos(), map_symbols::space);
			bullets.erase(bullets.begin() + i);
		}
	}
}

void World::checkbullets(vector<Bullet> &bullets, vector<Ship> &enemies) {
	int count_bullets = bullets.size();
	int count_enemies = enemies.size();

	for (int i = count_bullets - 1; i >= 0; i--) {
		if (map[bullets[i].get_y_pos()][bullets[i].get_x_pos()] == map_symbols::enemy) {
			SetMapSymbol(bullets[i].get_x_pos() - 1, bullets[i].get_y_pos(), map_symbols::space);

			for (int j = count_enemies - 1; j >= 0; j--) {
				if (enemies[j].get_y_pos() == bullets[i].get_y_pos() && enemies[j].get_x_pos() == bullets[i].get_x_pos()) {
					enemies[j].ReceiveDamage(bullets[i].get_damage());
					if (enemies[j].get_current_health() <= 0) {
						SetMapSymbol(enemies[j].get_x_pos(), enemies[j].get_y_pos(), map_symbols::space);
						enemies.erase(enemies.begin() + j);
						count_enemies--;
					}
					break;
				}
			}

			bullets.erase(bullets.begin() + i);
		}
	}
}

void World::DrawMap() {
	SetCurPos(0, 2);

	for (int i = 2; i < width - 2; i++) {
		wprintf_s(L"%ls\n", map[i]);
	}
}