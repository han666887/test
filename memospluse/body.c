#define _CRT_SECURE_NO_WARNINGS
#include "memos.h"

//加载文件中信息
void LoodPeoInfo(Contact* pc) {
	int count = 0;
	FILE* p = fopen("test.txt", "r");
	if (p == NULL) {
		perror("open file for read");
		return;
	}
	else {
		while (1) {
			if ((pc->sz) == (pc->capacity)) {
				PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + 2));
				pc->capacity += 2;
				if (ptr != NULL) {
					pc->data = ptr;
				}
				else {
					perror("AddInfor::realloc");
					return;
				}
			}
			count = fscanf(p, "%10s%5s%5d%5s%12s%12s\n", pc->data[pc->sz].stunum, pc->data[pc->sz].name,
				&(pc->data[pc->sz].age), pc->data[pc->sz].sxe, pc->data[pc->sz].tell, pc->data[pc->sz].QQ);
			if (count != 6) {
				break;
			}
			(pc->sz)++;
		}
	}
	fclose(p);
	p = NULL;
}

//初始化
void InitContact(Contact* pc) {
	pc->data = (PeoInfo*)calloc(sizeof(PeoInfo) * 3,sizeof(PeoInfo));
	pc->capacity = 3;
	pc->sz = 0;
	if (pc->data == NULL) {
		perror("InitContact::calloc");
		return;
	}
	LoodPeoInfo(pc);
}

//增加信息
void AddInfor(Contact* pc) {
	if ((pc->sz) == (pc->capacity)) {
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, sizeof(PeoInfo) * (pc->capacity + 2));
		pc->capacity += 2;
		if (ptr != NULL) {
			pc->data = ptr;
		}
		else {
			perror("AddInfor::realloc");
			return;
		}
	}
	else {
		printf("请输入学号：");
		scanf("%s", (pc->data[pc->sz]).stunum);
		printf("请输入姓名：");
		scanf("%s", (pc->data[pc->sz]).name);
		printf("请输入年龄：");
		scanf("%d", &((pc->data[pc->sz]).age));
		printf("请输入性别：");
		scanf("%s", (pc->data[pc->sz]).sxe);
		printf("请输入电话：");
		scanf("%s", (pc->data[pc->sz]).tell);
		printf("请输入QQ：");
		scanf("%s", (pc->data[pc->sz]).QQ);
		pc->sz++;
		printf("添加成功\n");
	}

}


//查找
int Search(Contact* pc) {
	char stu[10] = { 0 };
	int k = pc->sz;
	if (k == 0) {
		printf("通讯录为空\n");
		return 1;
	}
	else {
		printf("请输入要查找的人的编号：");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				printf("%10s %5s %5s %5s %12s %12s\n", "学号", "姓名", "年龄", "性别", "电话", "QQ");
				printf("%10s %5s %5d %5s %12s %12s\n",
					pc->data[k - 1].stunum, pc->data[k - 1].name,
					pc->data[k - 1].age, pc->data[k - 1].sxe,
					pc->data[k - 1].tell, pc->data[k - 1].QQ);
				/*ShowInfor(pc);*/
				return k;
			}
			k--;
		}
		if (k == 0) {
			printf("查无此人\n");
			return 0;
		}
	}
	return 1;
}


int MySearchForDel(Contact* pc) {
	char stu[10] = { 0 };
	int k = pc->sz;
	if (k == 0) {
		printf("通讯录为空\n");
		return 1;
	}
	else {
		printf("请输入要删除的人的编号：");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				return k;
			}
			k--;
		}
		if (k == 0) {
			printf("无此人\n");
			return 0;
		}
	}
	return 1;
}

//删除
void DelInfor(Contact* pc) {
	int S = MySearchForDel(pc);
	if (S != 0) {
		for (int i = S - 1; i < pc->sz - 1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
		ShowInfor(pc);
	}
}


//打印
void ShowInfor(Contact* pc) {
	int i = 0;
	printf("%10s %5s %5s %5s %12s %12s\n", "学号", "姓名", "年龄", "性别", "电话", "QQ");
	for (i = 0; i < pc->sz; i++) {
		printf("%10s %5s %5d %5s %12s %12s\n",
			pc->data[i].stunum, pc->data[i].name,
			pc->data[i].age, pc->data[i].sxe,
			pc->data[i].tell, pc->data[i].QQ);
	}
}


int MySearchForMod(Contact* pc) {
	char stu[10] = { 0 };
	int k = pc->sz;
	if (k == 0) {
		printf("通讯录为空\n");
		return 1;
	}
	else {
		printf("请输入要修改的人的编号：");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				return k;
			}
			k--;
		}
		if (k == 0) {
			printf("无此人\n");
			return 0;
		}
	}
	return 1;
}

//修改
void ModifyInfor(Contact* pc) {
	int S = MySearchForMod(pc);
	if (S != 0) {
		printf("请输入学号：");
		scanf("%s", (pc->data[S - 1]).stunum);
		printf("请输入姓名：");
		scanf("%s", (pc->data[S - 1]).name);
		printf("请输入年龄：");
		scanf("%d", &((pc->data[S - 1]).age));
		printf("请输入性别：");
		scanf("%s", (pc->data[S - 1]).sxe);
		printf("请输入电话：");
		scanf("%s", (pc->data[S - 1]).tell);
		printf("请输入QQ：");
		scanf("%s", (pc->data[S - 1]).QQ);

		printf("修改成功\n");
		ShowInfor(pc);
	}
}


int compare(const void* p1, const void* p2) {
	return strcmp(((PeoInfo*)p1)->stunum, ((PeoInfo*)p2)->stunum);
}

//排序
void SortInfor(Contact* pc) {
	if (pc->sz != 0) {
		qsort((pc->data), pc->sz, sizeof(pc->data[0]), compare);
		ShowInfor(pc);
	}
	else {
		printf("通讯录为空\n");
	}
}

//退出之前把信息保存在文件
void SaveInfor(Contact* pc) {
	FILE* p = fopen("test.txt", "w");
	int i = 0;
	if (p == NULL) {
		perror("open file for write");
		return;
	}
	else {
		/*fwrite(pc->data, sizeof(PeoInfo), pc->sz, p);*/
		for ( i = 0; i < pc->sz; i++) {
			fprintf(p, "%10s%5s%5d%5s%12s%12s\n", pc->data[i].stunum,
				pc->data[i].name, pc->data[i].age,
				pc->data[i].sxe, pc->data[i].tell,
				pc->data[i].QQ);
		}
	}
	fclose(p);
	p = NULL;
}