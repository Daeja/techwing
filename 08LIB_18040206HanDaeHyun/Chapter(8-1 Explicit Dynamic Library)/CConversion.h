// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// CHAPTER81HDH_DLIB_CHANGER_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef CHAPTER81HDH_DLIB_CHANGER_EXPORTS
#define CHAPTER81HDH_DLIB_CHANGER_API __declspec(dllexport)
#else
#define CHAPTER81HDH_DLIB_CHANGER_API __declspec(dllimport)
#endif

#include "stdafx.h"

#define INITIALIZE		( 1 )
#define STRING_BUFFER	( 100 )

extern "C" CHAPTER81HDH_DLIB_CHANGER_API void CMyStringToChar(CMyString & input, char * & pcOutput);
extern "C" CHAPTER81HDH_DLIB_CHANGER_API void CharToCMyString(char * & pcInput, CMyString & output);
extern "C" CHAPTER81HDH_DLIB_CHANGER_API void IntegerToCMyString(int & nInput, CMyString & output);
extern "C" CHAPTER81HDH_DLIB_CHANGER_API void IntegerToChar(int & nInput, char * & pcOutput);
extern "C" CHAPTER81HDH_DLIB_CHANGER_API void DoubleToCMyString(double & dInput, CMyString & output);
extern "C" CHAPTER81HDH_DLIB_CHANGER_API void DoubleToChar(double & dInput, char * & pcOutput);


// �� Ŭ������ Chapter(8-1 HDH_DLIB_Changer).dll���� ������ ���Դϴ�.
class CHAPTER81HDH_DLIB_CHANGER_API CChapter81HDH_DLIB_Changer {
public:
	CChapter81HDH_DLIB_Changer(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

extern CHAPTER81HDH_DLIB_CHANGER_API int nChapter81HDH_DLIB_Changer;

CHAPTER81HDH_DLIB_CHANGER_API int fnChapter81HDH_DLIB_Changer(void);
