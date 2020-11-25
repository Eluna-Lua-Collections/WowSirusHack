#pragma once

#include "DllMain.h"

class Menu
{
private:
	BOOL state = FALSE;
public:
	void ToggleStateMenu();
	void DrawMenu(int& AddToSpeed);
	BOOL GetStateMenu();
};

