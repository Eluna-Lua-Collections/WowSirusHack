#pragma once
#include <vector>
#include <string>
#include "sdk.h"

unsigned FindAddrByOffsets(unsigned baseAdr, std::vector<unsigned> offsets);


C_BaseEntityStruct* GetPlayer();