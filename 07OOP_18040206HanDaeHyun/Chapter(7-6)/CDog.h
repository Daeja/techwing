#pragma once
#include "CLandAnimals.h"

class CDog : public CLandAnimals
{
public:
	CDog(void);
	~CDog(void);
	void crawl();
	void eats();
};

