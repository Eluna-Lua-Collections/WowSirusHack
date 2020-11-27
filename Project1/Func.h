#pragma once
#include <vector>
#include <string>
#include "sdk.h"
#include "DllMain.h"

struct SpeedHack {
	int DefaultSpeedPlayer = 7;
	int AddToSpeed = 0;
	int CurrentSpeed = 7;
	bool isActive = FALSE;
};

unsigned FindAddrByOffsets(unsigned baseAdr, std::vector<unsigned> offsets);
C_BaseEntityStruct* GetPlayer();
void CheckChangeSpeedPlayer(C_BaseEntityStruct*, SpeedHack& speedStruct);
void Teleport(float x, float y, float z);


