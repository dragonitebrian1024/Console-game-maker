#pragma once
#include <Windows.h>

void PlayAudio(LPCTSTR pszSound, HMODULE hmod, DWORD fdwSound);
void PlayAudioRepeated(LPCTSTR pszSound, HMODULE hmod, DWORD fdwSound, int waitTime, int howmany);