#include <Windows.h>
#include <iostream>
#include "sdk.h"
HMODULE hInstDll;

//typedef LocalPlayer* getEntity();



void CreateConsole()
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}


void Inject()
{
	CreateConsole();
	std::cout << "INJECTED" << '\n';

	while (!GetAsyncKeyState(VK_DELETE) & 1)
	{
		if (GetAsyncKeyState(VK_INSERT) & 1)
		{
			//getEntity *Entity = (getEntity*)0x4038F0;
			//LocalPlayer* player = reinterpret_cast<LocalPlayer*>(&Entity + 0x4);
			//std::cout << player->Health << '\n';
		}
	}
	std::cout << "UNINJECTED" << '\n';
	FreeConsole();
	FreeLibraryAndExitThread(hInstDll, 0);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)  
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			hInstDll = hinstDLL;
			CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Inject), NULL, NULL, NULL);
		}

		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
		}
		return TRUE;
}
