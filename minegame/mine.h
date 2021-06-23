#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
#define setmine  10

#define hang 9
#define lie 9

#define hangs 11
#define lies 11

//³õÊ¼»¯ÆåÅÌ
void Initboard(char board[hangs][lies], int Hangs, int Lies,char set);

//´òÓ¡ÆåÅÌ
void Displayboard(char board[hangs][lies], int Hangs, int Lies);
//²¼À×
void Setmine(char board[hangs][lies], int Hang, int Lie);
//É¨À×
void Findmines(char board[hangs][lies], int Hang, int Lie);