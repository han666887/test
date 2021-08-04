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
//枚举选择菜单的情况
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
	Contact Con = { 0 };//创建通讯录
	InitContact(&Con);//初始化
	int input = 0;
	do {
		printf("请输入：");
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
			printf("输入错误，请从新输入：");
			break;
		}
	} while (input);
	free(Con.data);
	Con.data = NULL;
	return 0;
}