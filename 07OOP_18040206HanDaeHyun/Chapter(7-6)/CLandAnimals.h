#pragma once
#include "CPets.h"

class CLandAnimals : public CPets
{
public:
	CLandAnimals(void);
	~CLandAnimals(void);
	void crawl();
	void eats();
};