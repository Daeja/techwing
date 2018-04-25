#include "CDog.h"
#include "CCat.h"
#include "CGoldfish.h"

#include "CRectangle.h"
#include "CTriangle.h"

int main()
{
	cout << "7-6-1 �����Դϴ�." << endl;

	CDog dog;
	CCat cat;
	CGoldfish goldFish;

	dog.crawl();
	dog.eats();

	cat.crawl();
	cat.eats();

	goldFish.swim();
	goldFish.eats();

	cout << endl << endl;
	cout << "7-6-2 �����Դϴ�." << endl;

	CRectangle rectangle;
	CTriangle triangle;

	rectangle.setArea(10.5, 20.5);
	triangle.setArea(5.0, 7.0);

	cout << rectangle.getArea() << endl;
	cout << triangle.getArea() << endl;

	return 0;
}