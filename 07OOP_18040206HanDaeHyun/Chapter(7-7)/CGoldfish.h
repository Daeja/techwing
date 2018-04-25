#pragma once
#include "CPets.h"
#include "IUnderwaterAnimals.h"

class CGoldfish : public CPets, public IUnderwaterAnimals
{
public:
	CGoldfish(void);
	~CGoldfish(void);
	void eat();
	void swim();
};