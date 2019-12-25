#include <time.h>

#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
	clock_t time_from_last = 0; // ���������� ������ �����, ��������� � ���������� ������
public:
	clock_t get_time();
	void add_time(clock_t time);
	void reset_time(); // ������������� �������� ���������� time_from_last � ����
	void set_time(clock_t new_time);
};

#endif // !TIMER_H

