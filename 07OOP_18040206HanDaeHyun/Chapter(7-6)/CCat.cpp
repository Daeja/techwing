#include "CCat.h"

/********************************************************************************
AUTHOR		: 한대현
NAME		: CCat
RETURNS		: 반환값 X
COMMENTS	: 디폴트 생성자
********************************************************************************/
CCat::CCat(void)
{
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: ~CCat
RETURNS		: 반환값 X
COMMENTS	: 디폴트 소멸자
********************************************************************************/
CCat::~CCat(void)
{
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: crawl
RETURNS		: 반환값 X
COMMENTS	: "살금살금" 출력
********************************************************************************/
void CCat::crawl()
{
	cout << "살금살금" << endl;
}

/********************************************************************************
AUTHOR		: 한대현
NAME		: eats
RETURNS		: 반환값 X
COMMENTS	: "고양이가 밥을 먹습니다." 출력
********************************************************************************/
void CCat::eats()
{
	cout << "고양이가 밥을 먹습니다." << endl;
}