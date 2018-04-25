#pragma once
#include "CDog.h"

class CBulldog : public CDog
{
public:
	CBulldog(void);
	~CBulldog(void);
	void eat();
	void bark();
	void crawl();
};

