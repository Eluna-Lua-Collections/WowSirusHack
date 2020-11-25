#pragma once

#define DEBUG

#ifdef DEBUG
	#include <iostream>
#endif


#include "sdk.h"
#include "DllMain.h"
#include "Func.h"
#include "Menu.h"

#include <Windows.h>

#include <vector>

#include "detours.h"
#include "../imgGui/imgui.h"
#include "../imgGui/imgui_impl_dx9.h"
#include "../imgGui/imgui_impl_win32.h"

#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "detours.lib")


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef HRESULT(__stdcall * f_EndScene)(IDirect3DDevice9 * pDevice); 


namespace ImportantCoords {
	struct Ogrimmar {
		float x = 1668.38;
		float y = -4434.13;
		float z = 19.6286;
	};

	struct Dalaran {

	};
}
void CreateConsole();

