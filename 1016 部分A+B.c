//1016 部分A+B
//这个很简单咯，简单一算10的9次方用int也能表示。不过还是用string接收更简单！！
//注意C语言中^是异或的意思不是乘方

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main() {
	char a[11] = {};
	char b[11] = {};
	int num_a=0 , num_b = 0;
	scanf("%s %d %s %d", a, &num_a, b, &num_b);
	int len_a = strlen(a);
	int len_b = strlen(b);
	int count_a = 0, count_b = 0;
	for (int i = 0; i < len_a; i++) {
		if (a[i] - '0' == num_a) {
			count_a++;
		}
	}
	for (int i = 0; i < len_b; i++) {
		if (b[i] - '0' == num_b) {
			count_b++;
		}
	}
	//原来这里用的是计算权重weight的方式。有更简单的方法，下面写了秦九韶算法
	/*int sum = 0;
	int weight = 1;
	for (int i = 0; i < count_a; i++) {
		for (int j = 0; j < i; j++) {
			weight *= 10;
		}
		sum += (num_a * weight);
		weight = 1;
	}
	
	for (int i = 0; i < count_b; i++) {
		for (int j = 0; j < i; j++) {
			weight *= 10;
		}
		sum += (num_b * weight);
		weight = 1;
	}*/
	int sum_a = 0,sum_b=0,sum=0;
	for (int temp = 0; temp < count_a; temp++) {
		sum_a =  sum_a * 10+num_a;
	}
	for (int temp = 0; temp < count_b; temp++) {
		sum_b =  sum_b * 10+num_b;
	}
	sum = sum_a + sum_b;
	printf("%d", sum);
	return 0;
}
