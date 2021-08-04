#define _CRT_SECURE_NO_WARNINGS
#include "memos.h"

//�����ļ�����Ϣ
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

//��ʼ��
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

//������Ϣ
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
		printf("������ѧ�ţ�");
		scanf("%s", (pc->data[pc->sz]).stunum);
		printf("������������");
		scanf("%s", (pc->data[pc->sz]).name);
		printf("���������䣺");
		scanf("%d", &((pc->data[pc->sz]).age));
		printf("�������Ա�");
		scanf("%s", (pc->data[pc->sz]).sxe);
		printf("������绰��");
		scanf("%s", (pc->data[pc->sz]).tell);
		printf("������QQ��");
		scanf("%s", (pc->data[pc->sz]).QQ);
		pc->sz++;
		printf("��ӳɹ�\n");
	}

}


//����
int Search(Contact* pc) {
	char stu[10] = { 0 };
	int k = pc->sz;
	if (k == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return 1;
	}
	else {
		printf("������Ҫ���ҵ��˵ı�ţ�");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				printf("%10s %5s %5s %5s %12s %12s\n", "ѧ��", "����", "����", "�Ա�", "�绰", "QQ");
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
			printf("���޴���\n");
			return 0;
		}
	}
	return 1;
}


int MySearchForDel(Contact* pc) {
	char stu[10] = { 0 };
	int k = pc->sz;
	if (k == 0) {
		printf("ͨѶ¼Ϊ��\n");
		return 1;
	}
	else {
		printf("������Ҫɾ�����˵ı�ţ�");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				return k;
			}
			k--;
		}
		if (k == 0) {
			printf("�޴���\n");
			return 0;
		}
	}
	return 1;
}

//ɾ��
void DelInfor(Contact* pc) {
	int S = MySearchForDel(pc);
	if (S != 0) {
		for (int i = S - 1; i < pc->sz - 1; i++) {
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("ɾ���ɹ�\n");
		ShowInfor(pc);
	}
}


//��ӡ
void ShowInfor(Contact* pc) {
	int i = 0;
	printf("%10s %5s %5s %5s %12s %12s\n", "ѧ��", "����", "����", "�Ա�", "�绰", "QQ");
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
		printf("ͨѶ¼Ϊ��\n");
		return 1;
	}
	else {
		printf("������Ҫ�޸ĵ��˵ı�ţ�");
		scanf("%s", stu);
		while (k) {
			if (strcmp((pc->data[k - 1]).stunum, stu) == 0) {
				return k;
			}
			k--;
		}
		if (k == 0) {
			printf("�޴���\n");
			return 0;
		}
	}
	return 1;
}

//�޸�
void ModifyInfor(Contact* pc) {
	int S = MySearchForMod(pc);
	if (S != 0) {
		printf("������ѧ�ţ�");
		scanf("%s", (pc->data[S - 1]).stunum);
		printf("������������");
		scanf("%s", (pc->data[S - 1]).name);
		printf("���������䣺");
		scanf("%d", &((pc->data[S - 1]).age));
		printf("�������Ա�");
		scanf("%s", (pc->data[S - 1]).sxe);
		printf("������绰��");
		scanf("%s", (pc->data[S - 1]).tell);
		printf("������QQ��");
		scanf("%s", (pc->data[S - 1]).QQ);

		printf("�޸ĳɹ�\n");
		ShowInfor(pc);
	}
}


int compare(const void* p1, const void* p2) {
	return strcmp(((PeoInfo*)p1)->stunum, ((PeoInfo*)p2)->stunum);
}

//����
void SortInfor(Contact* pc) {
	if (pc->sz != 0) {
		qsort((pc->data), pc->sz, sizeof(pc->data[0]), compare);
		ShowInfor(pc);
	}
	else {
		printf("ͨѶ¼Ϊ��\n");
	}
}

//�˳�֮ǰ����Ϣ�������ļ�
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