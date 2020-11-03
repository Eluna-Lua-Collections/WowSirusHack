#include <Windows.h>
#include <iostream>
HMODULE hInstDll;

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
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Inject, NULL, NULL, NULL);
	}

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;

}