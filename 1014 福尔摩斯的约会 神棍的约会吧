//1014 福尔摩斯的约会
//这是福尔摩斯啊，这不神棍吗

//题目倒是应该不难，输出星期的英文的话可以参考1002 写出这个数  
//这玩意儿题目描述真不清楚吧，说的啥啊都是
//没力气了随便一写

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
const char* DD[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
int main() {
	char arr1[60] = {};
	char arr2[60] = {};
	char arr3[60] = {};
	char arr4[60] = {};
	scanf("%s", arr1);
	scanf("%s", arr2);
	scanf("%s", arr3);
	scanf("%s", arr4);
	int i = 0;
	int count = 0;
	for (i = 0; i < strlen(arr1); i++) {
		if (arr1[i] >= 'A' && arr1[i] <= 'G') {
			if (arr2[i] >='A'&&arr2[i]<='G') {
				if (arr1[i] == arr2[i]) {
					int temp = arr2[i] - 'A';
					printf("%s ", DD[temp]);
					break;
				}
			}
		}
	}
	for (i++; i < strlen(arr1); i++) {
		if ((arr1[i] >= 'A' && arr1[i] <= 'N')|| (arr1[i] >= '0' && arr1[i] <= '9')) {
			if ((arr2[i] >= 'A' && arr2[i] <= 'N') || (arr2[i] >= '0' && arr2[i] <= '9')) {
				if (arr2[i] == arr1[i]) {
						int temp;
						if (arr2[i] >= '0' && arr2[i] <= '9') {
							temp = arr2[i] - '0';
							printf("0");
						}
						else {
							temp = arr2[i] - 'A'+10;
						}
						printf("%d:", temp);
						break;
				}
			}
		}
	}
	for (i = 0; i < strlen(arr3); i++) {
		if ((arr3[i] >= 'a' && arr3[i] <= 'z')|| (arr3[i] >= 'A' && arr3[i] <= 'Z')) {
			if ((arr4[i] >= 'a' && arr4[i] <= 'z') || (arr4[i] >= 'A' && arr4[i] <= 'Z')) {
				if (arr3[i] == arr4[i]) {
					if (i <= 9) {
						printf("0");
					}
					printf("%d", i);
					break;
				}
			}
		}
	}
	return 0;
}
