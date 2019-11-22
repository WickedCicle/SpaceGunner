#ifndef ACTOR_H
#define ACTOR_H

class Actor {
private:
	int x;
	int y;
public:
	Actor(int new_x, int new_y) { x = new_x; y = new_y; }

	int get_x_pos();
	void set_x_pos(int new_x);

	int get_y_pos();
	void set_y_pos(int new_y);
};

#endif // !ACTOR_H
