#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  hang  3
#define  lie  3

//��ʼ������
void Initboard(char board[hang][lie], int Hang, int Lie);
//��ӡ����
void Displayboard(char board[hang][lie], int Hang, int Lie);
//���
void Pleargame(char board[hang][lie], int Hang, int Lie);
//����
void Windowsgame(char board[hang][lie], int Hang, int Lie);
//��Ϸ����
char Win(char board[hang][lie], int Hang, int Lie);