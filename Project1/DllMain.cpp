#include "DllMain.h"
SpeedHack speedHackStruct;
Menu MyMenu;
const char* windowName = "World of Warcraft";
f_EndScene oEndScene;
HMODULE hInstDll;
WNDPROC oWndProc;


LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (MyMenu.GetStateMenu())
	{
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


HRESULT __stdcall Hooked_EndScene(IDirect3DDevice9 * pDevice) 
{
	if (GetAsyncKeyState(VK_NUMPAD0) & 1 )
		MyMenu.ToggleStateMenu();

	if (MyMenu.GetStateMenu())
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
		MyMenu.DrawMenu(speedHackStruct.AddToSpeed);
		std::cout << speedHackStruct.AddToSpeed << '\n';
	}

	return oEndScene(pDevice); 
}



void Inject()
{
	CreateConsole();
	std::cout << "INJECTED" << '\n';
	C_BaseEntityStruct* player = GetPlayer();

	HWND  window = FindWindowA(NULL, windowName);
	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWL_WNDPROC, (LONG_PTR)WndProc);
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

	void** vTable = *reinterpret_cast<void***>(pDevice);
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