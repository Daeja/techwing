#pragma once
#include "CPets.h"
#include "ILandAnimals.h"

class CDog : public CPets, public ILandAnimals
{
public:
	CDog(void);
	~CDog(void);
	void eat();
	void bark();
	void crawl();
};
