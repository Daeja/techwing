// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// CHAPTER83HDH_DLIB_MATH_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef CHAPTER83HDH_DLIB_MATH_EXPORTS
#define CHAPTER83HDH_DLIB_MATH_API __declspec(dllexport)
#else
#define CHAPTER83HDH_DLIB_MATH_API __declspec(dllimport)
#endif

extern "C" CHAPTER83HDH_DLIB_MATH_API int iPower(int nA, int nB);
extern "C" CHAPTER83HDH_DLIB_MATH_API int getGCD(int nA, int nB);
extern "C" CHAPTER83HDH_DLIB_MATH_API int getLCM(int nA, int nB);

// �� Ŭ������ Chapter(8-3 HDH_DLIB_Math).dll���� ������ ���Դϴ�.
class CHAPTER83HDH_DLIB_MATH_API CChapter83HDH_DLIB_Math {
public:
	CChapter83HDH_DLIB_Math(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

extern CHAPTER83HDH_DLIB_MATH_API int nChapter83HDH_DLIB_Math;

CHAPTER83HDH_DLIB_MATH_API int fnChapter83HDH_DLIB_Math(void);
