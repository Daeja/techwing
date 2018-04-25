#pragma once
#define interface class

interface ILandAnimals
{
public:
	~ILandAnimals(void);
	virtual void crawl() = 0;
};

