#include "Timer.h"

clock_t Timer::get_time() {
	return time_from_last;
}

void Timer::add_time(clock_t time) {
	time_from_last += time;
}

void Timer::reset_time() {
	time_from_last = 0;
}

void Timer::set_time(clock_t new_time) {
	time_from_last = new_time - time_from_last;
}