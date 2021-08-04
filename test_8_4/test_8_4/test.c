#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
////第一种
//int my_strlen(const char* str) {
//	assert(str);
//	int count = 0;
//	while (*str++) {
//		count++;
//	}
//	return count;
//}
//
////第二种
//int my_strlen(const char* str) {
//	assert(str);
//	char* ch = str;
//	while (*str) {
//		str++;
//	}
//	return str-ch;
//}
//
////第三种
//int my_strlen(const char* str) {
//	assert(str);
//	if (*str == '\0') {
//		return 0;
//	}
//	else {
//		return 1 + my_strlen(++str);
//	}
//}
//int main() {
//	char arr[] = "abcdefg";
//	printf("%d",my_strlen(arr));
//	return 0;
//}

#include <stdio.h>
#include <assert.h>
void my_strcpy(char* dest, const char* src) {
	assert(dest && src);
	char* p = dest;
	while (*dest++ = *src++) {
		;
	}
	while (*p) {
		printf("%c", *p++);
	}
}
int main() {
	char arr1[] = "abcdefg";
	char arr2[10] = { 0 };
	my_strcpy(arr2, arr1);
	return 0;
}