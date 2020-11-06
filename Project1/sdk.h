#pragma once

#include <Windows.h>
#include <cstdint>




class C_BaseEntityStruct
{
public:
	char pad_0000[16]; //0x0000
	float CoordX; //0x0010
	float CoordY; //0x0014
	float CoordZ; //0x0018
	double Rotate; //0x001C
	double N00000057; //0x0024
	char pad_002C[112]; //0x002C
	float Speed; //0x009C
	char pad_00A0[12]; //0x00A0
	float RotateSpeed; //0x00AC
	char pad_00B0[1912]; //0x00B0
	int32_t Health; //0x0828
	int32_t Mana; //0x082C
	char pad_0830[280]; //0x0830
}; //Size: 0x0948
