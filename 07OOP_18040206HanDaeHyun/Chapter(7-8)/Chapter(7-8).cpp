#include "CLogger.h"

int main()
{
	// char * pcFileNameExtension = "txt";
	char * pcFileNameExtension = NULL;

	CLogger logger(pcFileNameExtension);

	char * pcContent1 = "J015::Tray Flow Feeder Up/Down Cylinder 가(이) (하강) 동작 이상입니다.";
	char * pcContent2 = "Handler Running Stop";
	char * pcContent3 = "Handler Running Start";
	char * pcContent4 = "Z002::상단 Stacker(스테커) 도어가 열려있어 운전 할 수 없습니다.!!!";
	char * pcContent5 = "N420::정상적으로 원점 복귀가 끝났습니다.!!!";
	char * pcContent6 = "Z032::티칭 화면을 저어말로 실행합니까 ?";
	char * pcContent7 = "C014::LOAD::Preciser Up/Down Cylinder 가(이) (상승) 동작 이상입니다.";
	char * pcContent8 = "내 이름은 한대현";
	char * pcContent9 = "S/W 3팀 한대현 연구원";
	
	logger.write(pcContent1);
	logger.write(pcContent2);
	logger.write(pcContent3);
	logger.write(pcContent4);

	Sleep(3000);

	if( true == 1 )
	{
		logger.write(pcContent5);
	}
	else
	{
		logger.write(pcContent6);
	}
	
	logger.write(pcContent7);
	logger.write(pcContent8);

	Sleep(1000);

	logger.write(pcContent9);

	logger.write(NULL);		// 방어코드 작성

	return 0;
}