// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// HDH_DLIB_ARITHMETIC_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#ifdef HDH_DLIB_ARITHMETIC_EXPORTS
#define HDH_DLIB_ARITHMETIC_API __declspec(dllexport)
#else
#define HDH_DLIB_ARITHMETIC_API __declspec(dllimport)
#endif

extern "C" HDH_DLIB_ARITHMETIC_API int addition(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int subtraction(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int multiplication(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int division(int nA, int nB);

// �� Ŭ������ HDH_DLIB_Arithmetic.dll���� ������ ���Դϴ�.
class HDH_DLIB_ARITHMETIC_API CHDH_DLIB_Arithmetic {
public:
	CHDH_DLIB_Arithmetic(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};

extern HDH_DLIB_ARITHMETIC_API int nHDH_DLIB_Arithmetic;

HDH_DLIB_ARITHMETIC_API int fnHDH_DLIB_Arithmetic(void);
