#define _CRT_SECURE_NO_WARNINGS
#include "mine.h"

//��ӡ�˵�
void mune() {
	printf("********************\n");
	printf("******1. play  *****\n");
	printf("******2. exit  *****\n");
	printf("********************\n");
}

//����Ϸ
void game() {
	//������ά����
	char mine[hangs][lies] = { 0 };
	char show[hangs][lies] = { 0 };
	//��ʼ������
	Initboard(mine, hangs, lies,'0');
	Initboard(show, hangs, lies,'*');
	//��ӡ����
	Displayboard(show, hangs, lies);
	//Displayboard(mine, hangs, lies);
	//����
	Setmine(mine, hang, lie);
	Displayboard(mine, hangs, lies);
	//ɨ��
	Findmines(show,mine, hang, lie);


}

int main()
{
	int input = 0;
	do {
		mune();
		srand((unsigned int)time(NULL));
		scanf_s("%d", &input);
		switch(input){
		case 1:
			game();
			break;
		case 2:
			break;
		case 3:
			printf("���������������룺\n");
			break;
		}
	} while (input!=2);
	return 0;
}