#define _CRT_SECURE_NO_WARNINGS
//��������ż��λ��
//#include <stdio.h>
//int main() {
//	int arr[] = { 2,4,6,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int lift = 0;
//	int right = sz - 1;
//	int tmp = 0;
//	while (lift < right) {
//		while ((lift<right)&&(arr[lift] % 2 != 0)) {
//			lift++;
//		}
//		while ((lift < right) && (arr[right] % 2 == 0)) {
//			right--;
//		}
//		tmp = arr[lift];
//		arr[lift] = arr[right];
//		arr[right] = tmp;
//	}
//	for (int i = 0; i < sz; i++) {
//		printf("%d", arr[i]);
//	}
//	return 0;
//}


//����ˮ
//int main() {
//	int money = 0;
//	int total = 0;
//	scanf("%d", &money);
//	if (money == 0)
//		printf("0\n");
//	else
//	{
//		total = money * 2 - 1;
//		printf("%d\n", total);
//	}
//	return 0;
//}


//ָ�������ʹ��
//int main() {
//	int arr[][3] = { {1,2,3 },{ 4, 5, 6 }, {7, 8, 9 }};
//	int (*p)[3] =&arr;
//	printf("%p\n",p);//��һ��һά����ĵ�ַ
//	printf("%p\n", p + 1);//�ڶ���һά����ĵ�ַ���һ��һά�������12���ֽ�
//	printf("%p\n", *(p));//��һ��һά����ĵ�һ��Ԫ�صĵ�ַ
//	printf("%p\n", *(p + 1));//�ڶ���һά����ĵ�һ��Ԫ�صĵ�ַ
//	printf("%d\n", **p);//��һ��һά����ĵ�һ��Ԫ��
//	return 0;
//}
//


//#include <stdio.h>
//int main() {
//	char arr[] = "           ";
//	int sz = sizeof(arr); 
//	int mid = sz / 2;
//	for(int i=0;i<=5;i++){
//		arr[mid-1+i] = '*';
//		arr[mid-1 - i] = '*';
//		printf("%s\n", arr);
//	}
//	for (int j = 1; j <= 5; j++) {
//		arr[sz-1 - j] = ' ';
//		arr[j-1] = ' ';
//		printf("%s\n", arr);
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() {
//	int a = -2;
//	printf("%u\n", a);
//	unsigned int b = 1;
//	printf("%d", a + b);
//	return 0;
//}