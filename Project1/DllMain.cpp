#include <Windows.h>
#include <iostream>
#include "sdk.h"
#include "DllMain.h"
#include <vector>
HMODULE hInstDll;

//typedef LocalPlayer* getEntity();



void CreateConsole()
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}

unsigned FindAddrByOffsets(unsigned baseAdr, std::vector<unsigned> offsets)
{
	unsigned result = baseAdr;

	for (auto el : offsets)
	{
		result = *reinterpret_cast<unsigned*>(result);
		result += el;
	}
	return result;
}

void Inject()
{
	CreateConsole();
	std::cout << "INJECTED" << '\n';

	BOOL speedON = FALSE;

	unsigned baseAddr = (unsigned)(GetModuleHandle(TEXT("run.exe"))) + 0x006DB754;
	unsigned result = *(unsigned*)baseAddr + 0x38;
	result = *(unsigned*)result + 0x750;
	//unsigned result = FindAddrByOffsets(baseAddr, std::vector<unsigned>(0x7a8, 0x430));
	C_BaseEntityStruct* player = (C_BaseEntityStruct*)result;
	std::cout << result << '\n';
	while (!GetAsyncKeyState(VK_DELETE) & 1)
	{
		if (GetAsyncKeyState(VK_MBUTTON) & 1)
		{
			if (!speedON)
			{

				player->Speed = 100;
				speedON = TRUE;
				std::cout << "speedON" << '\n';
			}
			else
			{

				player->Speed = DEFAULT_SPEED_PLAYER;
				speedON = FALSE;
				std::cout << "speedOFF" << '\n';
			}
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
