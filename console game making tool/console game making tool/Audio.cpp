#include "Audio.h"

void PlayAudio(LPCTSTR pszSound, HMODULE hmod, DWORD fdwSound) {
	PlaySound(pszSound, hmod, fdwSound);
}

void PlayAudioRepeated(LPCTSTR pszSound, HMODULE hmod, DWORD fdwSound, int waitTime, int howmany) {
	for (int g = 0; g < howmany; g++) {
		int Wait = waitTime;
		PlayAudio(pszSound, hmod, fdwSound);
		if (Wait >= 0)
			Wait--;
	}
}