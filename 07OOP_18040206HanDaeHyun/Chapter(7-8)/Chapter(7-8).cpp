#include "CLogger.h"

int main()
{
	// char * pcFileNameExtension = "txt";
	char * pcFileNameExtension = NULL;

	CLogger logger(pcFileNameExtension);

	char * pcContent1 = "J015::Tray Flow Feeder Up/Down Cylinder ��(��) (�ϰ�) ���� �̻��Դϴ�.";
	char * pcContent2 = "Handler Running Stop";
	char * pcContent3 = "Handler Running Start";
	char * pcContent4 = "Z002::��� Stacker(����Ŀ) ��� �����־� ���� �� �� �����ϴ�.!!!";
	char * pcContent5 = "N420::���������� ���� ���Ͱ� �������ϴ�.!!!";
	char * pcContent6 = "Z032::ƼĪ ȭ���� ����� �����մϱ� ?";
	char * pcContent7 = "C014::LOAD::Preciser Up/Down Cylinder ��(��) (���) ���� �̻��Դϴ�.";
	char * pcContent8 = "�� �̸��� �Ѵ���";
	char * pcContent9 = "S/W 3�� �Ѵ��� ������";
	
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

	logger.write(NULL);		// ����ڵ� �ۼ�

	return 0;
}