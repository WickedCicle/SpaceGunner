#include <Windows.h>
#include <thread>

#pragma comment(lib, "winmm.lib")

using namespace std;

#ifndef SOUNDS_H
#define SOUNDS_H

void Sound(LPCSTR SoundPath);
void SoundPlay(LPCSTR SoundPath);

#endif