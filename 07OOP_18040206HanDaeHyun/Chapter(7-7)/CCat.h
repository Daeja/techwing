#pragma once
#include "CPets.h"
#include "ILandAnimals.h"

class CCat : public CPets, public ILandAnimals
{
public:
	CCat(void);
	~CCat(void);
	void eat();
	void bark();
	void crawl();
};

