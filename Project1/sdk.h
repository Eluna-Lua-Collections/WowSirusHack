#pragma once

#include <Windows.h>
#include <cstdint>

class LocalPlayer
{
public:
	char pad_0000[16]; //0x0000
	float CoordX; //0x0010
	float CoordY; //0x0014
	float CoordZ; //0x0018
	char pad_001C[120]; //0x001C
	float Speed; //0x0094
	char pad_0098[1936]; //0x0098
	int32_t Health; //0x0828
	int32_t Mana; //0x082C
	char pad_0830[280]; //0x0830
}; //Size: 0x0948
