// 다음 ifdef 블록은 DLL에서 내보내기하는 작업을 쉽게 해 주는 매크로를 만드는 
// 표준 방식입니다. 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 _EXPORTS 기호로
// 컴파일되며, 다른 프로젝트에서는 이 기호를 정의할 수 없습니다.
// 이렇게 하면 소스 파일에 이 파일이 들어 있는 다른 모든 프로젝트에서는 
// HDH_DLIB_ARITHMETIC_API 함수를 DLL에서 가져오는 것으로 보고, 이 DLL은
// 이 DLL은 해당 매크로로 정의된 기호가 내보내지는 것으로 봅니다.
#ifdef HDH_DLIB_ARITHMETIC_EXPORTS
#define HDH_DLIB_ARITHMETIC_API __declspec(dllexport)
#else
#define HDH_DLIB_ARITHMETIC_API __declspec(dllimport)
#endif

extern "C" HDH_DLIB_ARITHMETIC_API int addition(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int subtraction(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int multiplication(int nA, int nB);
extern "C" HDH_DLIB_ARITHMETIC_API int division(int nA, int nB);

// 이 클래스는 HDH_DLIB_Arithmetic.dll에서 내보낸 것입니다.
class HDH_DLIB_ARITHMETIC_API CHDH_DLIB_Arithmetic {
public:
	CHDH_DLIB_Arithmetic(void);
	// TODO: 여기에 메서드를 추가합니다.
};

extern HDH_DLIB_ARITHMETIC_API int nHDH_DLIB_Arithmetic;

HDH_DLIB_ARITHMETIC_API int fnHDH_DLIB_Arithmetic(void);
