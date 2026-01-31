//1006 换个格式输出整数
//OMG好神金，但是挺简单的，这里的思路是既然输入只有一个数，那就可以当作字符串输入，这样可以直接得到各位的数字
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

void printB(int n) {
	for (int t = 0; t < n; t++) {
		printf("B");
	}
}
void printS(int n) {
	for (int t = 0; t < n; t++) {
		printf("S");
	}
}
void printG(int n) {
	for (int t = 1; t <= n; t++) {
		printf("%d",t);
	}
}

int main() {
	char arr[4] = {};
	scanf("%s", arr);
	int n = 0;
	int t = strlen(arr);
	switch (t) {
	case 3:
		n = arr[0] - '0';
		printB(n);
		n = arr[1] - '0';
		printS(n);
		n = arr[2] - '0';
		printG(n);
		break;
	case 2:
		n = arr[0] - '0';
		printS(n);
		n = arr[1] - '0';
		printG(n);
		break;
	case 1:
		n = arr[0] - '0';
		printG(n);
		break;
	}
	return 0;
}
