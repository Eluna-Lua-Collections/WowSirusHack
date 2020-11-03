#include <Windows.h>
#include <iostream>
HMODULE hInstDll;


void Inject()
{


}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)  
{
	
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
	{
		hInstDll = hinstDLL;
		CreateThread(nullptr, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(Inject), nullptr, NULL, nullptr);

		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	return TRUE;
	}
}