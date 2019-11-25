#include "Sounds.h"

void Sound(LPCSTR SoundPath) {
	PlaySound(SoundPath, NULL, SND_ASYNC|SND_FILENAME); //SND_FILENAME or SND_LOOP
}

/*void Sound(LPCSTR SoundPath) {
	PlaySound(SoundPath, NULL, SND_FILENAME); //SND_FILENAME or SND_LOOP
}*/

void SoundPlay(LPCSTR SoundPath) {
	thread th(Sound, SoundPath);
	th.detach();
}
