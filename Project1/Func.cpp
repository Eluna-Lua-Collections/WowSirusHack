#include "Func.h"



unsigned FindAddrByOffsets(unsigned baseAdr, std::vector<unsigned> offsets)
{
	unsigned result = baseAdr;

	for (auto el : offsets)
	{
		result = *reinterpret_cast<unsigned*>(result);
		result += el;
	}
	return result;
}

C_BaseEntityStruct * GetPlayer()
{
	unsigned baseAddr = (unsigned)(GetModuleHandle(TEXT("run.exe"))) + 0x006DB754;
	unsigned result = *(unsigned*)baseAddr + 0x38;
	result = *(unsigned*)result + 0x750;
	return reinterpret_cast<C_BaseEntityStruct*>(result);
}

void CheckChangeSpeedPlayer(C_BaseEntityStruct* player, SpeedHack& speedStruct)
{
	player->Speed = speedStruct.CurrentSpeed;
}

void Teleport(float x, float y, float z)
{
	C_BaseEntityStruct* player = GetPlayer();
	player->CoordX = x;
	player->CoordY = y;
	player->CoordZ = z;
}

