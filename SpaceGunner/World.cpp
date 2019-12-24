#define _CRT_SECURE_NO_WARNINGS
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
}

void World::DrawBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets) {
	int count_bullets = bullets.size();
	int count_enemy_bullets = enemy_bullets.size();

	for (int i = 0; i < count_bullets; i++) {
		if (map[bullets[i].get_y_pos()][bullets[i].get_x_pos() - 1] == map_symbols::hero_bullet) {
			map[bullets[i].get_y_pos()][bullets[i].get_x_pos() - 1] = map_symbols::space;
		}
		map[bullets[i].get_y_pos()][bullets[i].get_x_pos()] = map_symbols::hero_bullet;
	}

	for (int i = 0; i < count_enemy_bullets; i++) {
		if (map[enemy_bullets[i].get_y_pos()][enemy_bullets[i].get_x_pos() + 1] == map_symbols::enemy_bullet) {
			map[enemy_bullets[i].get_y_pos()][enemy_bullets[i].get_x_pos() + 1] = map_symbols::space;
		}
		map[enemy_bullets[i].get_y_pos()][enemy_bullets[i].get_x_pos()] = map_symbols::enemy_bullet;
	}
}

void World::MoveBullets(vector<Bullet> &bullets, vector<Bullet> &enemy_bullets, Timer &Bullets_Move, Timer &Enemy_Bullets_Move) {
	if (Bullets_Move.get_time() > 1000/(length/2)) {
		int count_bullets = bullets.size();

		for (int i = 0; i < count_bullets; i++) {
			bullets[i].set_x_pos(bullets[i].get_x_pos() + 1);
		}
		Bullets_Move.reset_time();
	}

	if (Enemy_Bullets_Move.get_time() > 1000 / (length / 2)) {
		int count_enemy_bullets = enemy_bullets.size();

		for (int i = 0; i < count_enemy_bullets; i++) {
			enemy_bullets[i].set_x_pos(enemy_bullets[i].get_x_pos() - 1);
		}
		Enemy_Bullets_Move.reset_time();
	}
}

void World::SetMapSymbol(int x, int y, wchar_t symbol) {
	map[y][x] = symbol;
}

void World::checkbullets(Ship &Hero, vector<Bullet> &bullets, vector<Enemy> &enemies, vector<Bullet> &enemy_bullets, Settings_Args &SetArgs, int &Score) {
	int count_bullets = bullets.size();
	int count_enemies = enemies.size();
	int count_enemy_bullets = enemy_bullets.size();

	for (int i = count_enemy_bullets - 1; i >= 0; i--) {
		if (enemy_bullets[i].get_x_pos() == -1) {
			SetMapSymbol(enemy_bullets[i].get_x_pos() + 1, enemy_bullets[i].get_y_pos(), map_symbols::space);
			enemy_bullets.erase(enemy_bullets.begin() + i);
			continue;
		}
		if (map[enemy_bullets[i].get_y_pos()][enemy_bullets[i].get_x_pos()] == map_symbols::hero) {
			SetMapSymbol(enemy_bullets[i].get_x_pos() + 1, enemy_bullets[i].get_y_pos(), map_symbols::space);
			Hero.set_current_health(Hero.get_current_health() - 1);
			enemy_bullets.erase(enemy_bullets.begin() + i);
			if (Hero.get_current_health() <= 0) {
				Hero.DestroyShip();
			}
		}
	}

	for (int i = count_bullets - 1; i >= 0; i--) {
		if (bullets[i].get_x_pos() == length) {
			SetMapSymbol(bullets[i].get_x_pos() - 1, bullets[i].get_y_pos(), map_symbols::space);
			bullets.erase(bullets.begin() + i);
			continue;
		}

		if (map[bullets[i].get_y_pos()][bullets[i].get_x_pos()] == map_symbols::enemy) {
			SetMapSymbol(bullets[i].get_x_pos() - 1, bullets[i].get_y_pos(), map_symbols::space);

			for (int j = count_enemies - 1; j >= 0; j--) {
				if (enemies[j].get_y_pos() == bullets[i].get_y_pos() && enemies[j].get_x_pos() == bullets[i].get_x_pos()) {
					enemies[j].ReceiveDamage(bullets[i].get_damage());
					if (enemies[j].get_current_health() <= 0) {
						SetMapSymbol(enemies[j].get_x_pos(), enemies[j].get_y_pos(), map_symbols::space);
						enemies.erase(enemies.begin() + j);
						count_enemies--;
						Score += ((6 - SetArgs.Hero_health)*SetArgs.Enemy_health);
					}
					break;
				}
			}

			bullets.erase(bullets.begin() + i);
		}
	}
}

void World::CreateEnemies(vector<Enemy> &enemies, int Enemy_health, FirstEnemyPos &EnemyPos) {
	int count_row = 0;
	int count_column = 0;

	for (int i = 3; i < width - 3; i += 2) {
		for (int j = (3 * length) / 4; j < length; j += 2) {
			map[i][j] = map_symbols::enemy;
			enemies.push_back(Enemy(j, i, Enemy_health));
			count_column++;
		}
		count_row++;
	}

	EnemyPos.x = (3 * length) / 4;
	EnemyPos.y = 3;
	EnemyPos.count_row = count_row;
	EnemyPos.count_column = count_column/count_row;
}

void World::Enemy_Fire(vector<Bullet> &enemy_bullets, FirstEnemyPos &EnemyPos, Timer &EnemyFire) {
	bool column_found = false;
	int must_shoot = false;
	int row_count = 0;

	while (map[EnemyPos.y + 2 * row_count][EnemyPos.x + 2 * (EnemyPos.count_column - 1)] != map_symbols::border) {
		row_count++;
	}

	if (row_count < EnemyPos.count_row) {
		EnemyPos.count_row = row_count;
	}

	for (int i = 0; i < EnemyPos.count_row; i++) {
		for (int j = 0; j < EnemyPos.count_column; j++) {
			if (!column_found) {
				if (map[EnemyPos.y + 2 * i][EnemyPos.x + 2 * j] == map_symbols::enemy) {
					must_shoot = rand() % 150;
					if (must_shoot == 1) {
						enemy_bullets.push_back(Bullet(EnemyPos.x + 2 * j, EnemyPos.y + 2 * i));
					}
					column_found = true;
				}
			}
		}
		column_found = false;
	}
}

void World::Move_Enemies(vector<Enemy> &enemies, Timer &Enemy_Move, FirstEnemyPos &EnemyPos, Settings_Args &SetArgs, bool &Win, Ship &Hero) {
	static int forward = 0;
	int enemies_count = enemies.size();
	if (enemies_count == 0) {
		Win = true;
		return;
	}

	if (Enemy_Move.get_time() >= 200*pow(1.2, SetArgs.Enemy_health)) {
		for (int i = 0; i < enemies_count; i++) {
			if (enemies[i].get_x_pos() == 0) {
				Hero.DestroyShip();
			}

			if (enemies[i].get_direction() == direction::right && enemies[i].get_y_pos() >= (width - 3)) {
				for (int j = 0; j < enemies_count; j++) {
					enemies[j].reverse_dir();
				}
				break;
			}
			else if (enemies[i].get_direction() == direction::left && enemies[i].get_y_pos() <= 2) {
				for (int j = 0; j < enemies_count; j++) {
					enemies[j].reverse_dir();
				}
				break;
			}
			
		}
		//if (forward >= 7*pow(1.1, SetArgs.Enemy_health)) {
		if (forward >= 8) {
			for (int j = 0; j < enemies_count; j++) {
				SetMapSymbol(enemies[j].get_x_pos(), enemies[j].get_y_pos(), map_symbols::space);
				enemies[j].Move(-1, 0);
				SetMapSymbol(enemies[j].get_x_pos(), enemies[j].get_y_pos(), map_symbols::enemy);
			}
			EnemyPos.x -= 1;
			forward = 0;
		}

		for (int i = 0; i < enemies_count; i++) {
			if (enemies[i].get_direction() == direction::right) {
				SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::space);
				enemies[i].Move(0, 1);
				SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::enemy);
			}
			if (enemies[i].get_direction() == direction::left) {
				SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::space);
				enemies[i].Move(0, -1);
				SetMapSymbol(enemies[i].get_x_pos(), enemies[i].get_y_pos(), map_symbols::enemy);
			}
		}
		if (enemies[enemies_count - 1].get_direction() == direction::right) {
			EnemyPos.y += 1;
		}
		else {
			EnemyPos.y -= 1;
		}

		forward++;
		Enemy_Move.reset_time();
	}
}

void World::DrawMap(bool &EscapePressed) {
	if (!EscapePressed) {
		SetCurPos(0, 2);

		for (int i = 2; i < width - 2; i++) {
			wprintf_s(L"%ls\n", *(map + i));
		}
	}
	else {
		SetCurPos(0, 0);

		for (int i = 0; i < width; i++) {
			wprintf_s(L"%ls\n", *(map + i));
		}
		EscapePressed = false;
	}
}