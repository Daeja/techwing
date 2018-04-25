#include "CCircle.h"
#include "CTriangle.h"
#include "CRectangle.h"

#include "CDog.h"
#include "CBulldog.h"
#include "CCat.h"
#include "CDuck.h"
#include "CGoldfish.h"

#define SHAPE_COUNT (3)

int main()
{
	cout << "7-7-1 문제입니다." << endl;

	CShape * arrayOfShapes[3];

	arrayOfShapes[0] = new CRectangle();
	arrayOfShapes[1] = new CTriangle();
	arrayOfShapes[2] = new CCircle();

	for(int nI = 0; nI < SHAPE_COUNT; nI++)
	{
		arrayOfShapes[nI] -> draw();
	}

	cout << endl << endl << "7-7-2 문제입니다" << endl;

	CDog dog;
	CBulldog bulldog;
	CCat cat;
	CDuck duck;
	CGoldfish goldfish;

	dog.bark();
	dog.crawl();
	dog.eat();

	bulldog.bark();
	bulldog.crawl();
	bulldog.eat();

	cat.bark();
	cat.crawl();
	cat.eat();

	duck.bark();
	duck.crawl();
	duck.eat();
	duck.swim();

	goldfish.eat();
	goldfish.swim();

	return 0;
}