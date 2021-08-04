#define _CRT_SECURE_NO_WARNINGS
#include "memos.h"

void menu() {
	printf("******************************\n");
	printf("****** 1.add       2.del *****\n");
	printf("****** 3.search    4.modify***\n");
	printf("****** 5.sort      6.show ****\n");
	printf("******       0.exit       ****\n");
	printf("******************************\n");
}
//ö��ѡ��˵������
enum IN {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW
};

int main() {
	menu();
	Contact Con = { 0 };//����ͨѶ¼
	InitContact(&Con);//��ʼ��
	int input = 0;
	do {
		printf("�����룺");
		scanf("%d", &input);
		switch (input) {
		case ADD:
			AddInfor(&Con);
			break;
		case DEL:
			DelInfor(&Con);
			break;
		case SEARCH:
			Search(&Con);
			break;
		case MODIFY:
			ModifyInfor(&Con);
			break;
		case SORT:
			SortInfor(&Con);
			break;
		case SHOW:
			ShowInfor(&Con);
			break;
		case EXIT:
			SaveInfor(&Con);
			break;
		default:
			printf("���������������룺");
			break;
		}
	} while (input);
	free(Con.data);
	Con.data = NULL;
	return 0;
}