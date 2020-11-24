#include <Windows.h>
#include <iostream>
#include "sdk.h"
#include "DllMain.h"
#include <vector>
#include "detours.h"

#include "../imgGui/imgui.h"
#include "../imgGui/imgui_impl_dx9.h"
#include "../imgGui/imgui_impl_win32.h"


const char* windowName = "World of Warcraft";


#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "detours.lib")

typedef HRESULT(__stdcall * f_EndScene)(IDirect3DDevice9 * pDevice); // our function prototype 
f_EndScene oEndScene; // original endscene
HMODULE hInstDll;


HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9 * pDevice) // our hooked endscene
{
	static bool init = true;
	if (init)
	{
		init = false;
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();

		ImGui_ImplWin32_Init(FindWindowA(NULL, windowName));
		ImGui_ImplDX9_Init(pDevice);
	}


	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::Text("Hello, world!");


	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());


	return oEndScene(pDevice); // call original ensdcene so the game can draw
}



void Inject()
{


	ImportantCoords::Ogrimmar OgrMr;
	CreateConsole();
	std::cout << "INJECTED" << '\n';

	C_BaseEntityStruct* player = GetPlayer();

	IDirect3D9* pD3D = Direct3DCreate9(D3D_SDK_VERSION); // create IDirect3D9 object
	if (!pD3D)
		return;

	D3DPRESENT_PARAMETERS d3dparams = { 0 };
	d3dparams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dparams.hDeviceWindow = GetForegroundWindow();
	d3dparams.Windowed = true;

	IDirect3DDevice9* pDevice = nullptr;

	HRESULT result = pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, d3dparams.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dparams, &pDevice);
	if (FAILED(result) || !pDevice) {
		pD3D->Release();
		return;
	}
	//if device creation worked out -> lets get the virtual table:
	void** vTable = *reinterpret_cast<void***>(pDevice);

	//now detour:

	oEndScene = (f_EndScene)DetourFunction((PBYTE)vTable[42], (PBYTE)Hooked_EndScene);

	pDevice->Release();
	pD3D->Release();





	//while (!GetAsyncKeyState(VK_DELETE) & 1)
	//{
		
		
	//}
	//std::cout << "UNINJECTED" << '\n';
	//FreeConsole();
	//FreeLibraryAndExitThread(hInstDll, 0);
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



void CreateConsole()
{
	AllocConsole();
	FILE *f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}