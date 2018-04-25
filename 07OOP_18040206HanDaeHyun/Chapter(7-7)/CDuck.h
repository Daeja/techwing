#pragma once
#include "CPets.h"
#include "IUnderwaterAnimals.h"
#include "ILandAnimals.h"

class CDuck : public CPets, public IUnderwaterAnimals, public ILandAnimals
{
public:
	CDuck(void);
	~CDuck(void);
	void eat();
	void bark();
	void swim();
	void crawl();
};

