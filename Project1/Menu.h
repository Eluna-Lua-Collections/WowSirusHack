#pragma once
#include "Func.h"
#include "DllMain.h"

struct bulletForTp {
	const char* continent;
	const char* village;
	float x;
	float y;
	float z;
};



class Menu
{
private:
	BOOL state = FALSE;
public:
	void ToggleStateMenu();
	void DrawMenu(int& AddToSpeed, bool& isActive);
	BOOL GetStateMenu();
	std::vector<bulletForTp> allBulletForTpOutCalimdor;
	std::vector<bulletForTp> allBulletForTpOutBeyond;
	std::vector<bulletForTp> allBulletForTpOutDalaran;
};

