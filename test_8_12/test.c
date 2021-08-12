#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//bool leapyear(int year) {
//    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//}
//int main() {
//    int year = 0;
//    int mouth = 0;
//    while (scanf("%d%d", &year, &mouth) != EOF) {
//        getchar();
//        switch (mouth) {
//        case 1:
//        case 3:
//        case 5:
//        case 7:
//        case 8:
//        case 10:
//        case 12:
//            printf("%d\n", 31);
//            break;
//        case 4:
//        case 6:
//        case 9:
//        case 11:
//            printf("%d\n", 30);
//            break;
//        case 2:
//            if (leapyear(year)) {
//                printf("%d\n", 29);
//            }
//            else {
//                printf("%d\n", 28);
//            }
//            break;
//        default:
//            printf(" ‰»Î¥ÌŒÛ£°\n");
//            break;
//        }
//    }
//    return 0;
//}


//#define input 10
//void print(int(*p)[input]) {
//	int i = 0;
//	for (i = 0; i < input; i++) {
//		int j = 0;
//		for (j = 0; j <= i; j++) {
//			if (j == 0 || j == i) {
//				p[i][j] = 1;
//				printf("%d ", p[i][j]);
//			}
//			else {
//				p[i][j] = p[i - 1][j] + p[i - 1][j - 1];
//				printf("%d ", p[i][j]);
//			}
//		}
//		printf("\n");
//	}
//}
//int main() {
//	int arr[input][input];
//	print(arr);
//	return 0;
//}

//int main() {
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++) {
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'C') == 3) {
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf("% d % d" , a + b, c);
//	return 0;
//}

//int main() {
//	int A = 0, B = 0, C = 0, D = 0, E = 0;
//	for (A = 1; A <= 5; A++) {
//		for (B = 1; B <= 5; B++) {
//			for (C = 1; C <= 5; C++) {
//				for (D = 1; D <= 5; D++) {
//					for (E = 1; E <= 5; E++) {
//						if ((B == 2) + (A == 3) == 1 && (B==2) + (E==4) == 1 && (C==1) + (D==2) == 1 && (C==5) + (D==3) == 1 && (E==4) + (A==1) == 1&&A*B*C*D*E==120) {
//							printf("A=%d B=%d C=%d D=%d E=%d\n", A, B, C, D, E);
//
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//
//void LiftHand(char* str, int sz, int k) {
//	k = k % sz;
//	int i = 0;
//	for (i = 0; i < k; i++) {
//		int j = 0;
//		char ch = str[0];
//		for (j = 0; j < sz - 1; j++) {
//			str[j] = str[j + 1];
//		}
//		str[j] = ch;
//	}
//}
//int main() {
//	char arr[10] = "abcdefgh";
//	int sz = strlen(arr);
//	int k = 0;
//	scanf("%d", &k);
//	LiftHand(arr, sz, k);
//	printf("%s", arr);
//	return 0;
//}
//

int Judge(char* str1, char* str2, int sz) {
	int k = sz;
	while (k) {
	    int j = 0;
		char ch = str1[0];
		for (j = 0; j < sz - 1; j++) {
			str1[j] = str1[j + 1];
		}
		str1[j] = ch;
		if (strcmp(str1, str2) == 0) {
			return 1;
		}
		else {
			k--;
		}
	}
	return 0;
}
int main() {
	char str1[10] = "abcdefg";
	char str2[10] = "cdefgab";
	int sz = strlen(str1);
	printf("%d",Judge(str1, str2, sz));
	return 0;
}