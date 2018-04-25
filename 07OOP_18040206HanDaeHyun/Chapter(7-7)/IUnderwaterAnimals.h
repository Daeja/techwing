#pragma once
#define interface class

interface IUnderwaterAnimals
{
public:
	~IUnderwaterAnimals(void);
	virtual void swim() = 0;
};

