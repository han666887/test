#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//类qsort函数，主要是交换两个不相等的元素
void My_qsort(void* arr, int sz, int width, int(*cmp)(const void* e1, const void* e2)) {
	for (int i = 0; i < sz; i++) {
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)arr + j * width, (char*)arr + (j + 1) * width) > 0) {
				for (int k = 0; k < width; k++) {//按字节交换
					char tmp = *((char*)arr + j * width + k);
					*((char*)arr + j * width + k) = *((char*)arr + (j + 1) * width + k);
					*((char*)arr + (j + 1) * width + k) = tmp;
				}
			}
		}
	}
}

//判断两个整数的大小，大于返回正数，等于返回零，小于返回负数
int cmp_int(const void* e1, const void* e2) {
	return *(int*)e1 - *(int*)e2;
}

//正序打印整型数组
void test1() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	My_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < sz; i++) {
		printf("%d", arr[i]);
	}
}

struct stu {
	char name[20];
	int age;
};

//判断两个整数的大小，大于返回正数，等于返回零，小于返回负数
int cmp_stu_age(const void* e1, const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

//按年龄正序打印结构体
void test2() {
	struct stu arr[] = { {"zhangsan",20},{"lisi",50},{"wangwu",40}};
	int sz = sizeof(arr) / sizeof(arr[0]);
	My_qsort(arr, sz, sizeof(arr[0]), cmp_stu_age);
	for (int i = 0; i < sz; i++) {
		printf("%s %d\n", arr[i].name,arr[i].age);
	}

}

//判断两个字符串的大小，大于返回正数，等于返回零，小于返回负数
int cmp_stu_name(const void* e1, const void* e2) {
	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
}

//按姓名打印结构体
void test3() {
	struct stu arr[] = { {"zhangsan",20},{"lisi",50},{"wangwu",40} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	My_qsort(arr, sz, sizeof(arr[0]), cmp_stu_name);
	for (int i = 0; i < sz; i++) {
		printf("%s %d\n", arr[i].name, arr[i].age);
	}

}

int main() {
	test3();
	return 0;
}












//#include <stdlib.h>
//int test1(const void* e1,const void* e2) {
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main() {
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]),test1);
//	for (int i = 0; i < sz; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}



//五人比赛计算排名
//int main() {
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++) {
//		for (b = 1; b <= 5; b++) {
//			for (c = 1; c <= 5; c++) {
//				for (d = 1; d <= 5; d++) {
//					for (e = 1; e <= 5; e++) {
//						if ((b==2) + (a==3) == 1 && 
//							(b==2) + (e==4) == 1 && 
//							(c==1) + (d==2) == 1 && 
//							(c==5) + (d==3) == 1 && 
//							(e==4) + (a==1) == 1) {
//							if(a*b*c*d*e==120&&a+b+c+d+e==15)
//							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
//
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}


//猜凶手
//int main() {
//	int killer =97;
//	for (killer =97; killer <=100; killer++) {
//		if ((killer != 97) + (killer == 99) + (killer ==100 ) + (killer != 100) == 3) {
//			printf("%c", killer);
//		}
//	}
//	return 0;
//}


//打印杨辉三角
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//	int arr[10][10] = { 0 };
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j <= i; j++) {
//			if (i == j || j == 0) {
//				arr[i][j] = 1;
//				printf("%3d", arr[i][j]);
//			}
//			else {
//				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
//				printf("%3d", arr[i][j]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}