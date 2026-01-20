//1007 素数对猜想
//找相邻且相差为2的素数，这个也比较简单咯

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

int is_prime(int num) {
	if (num == 1) {
		return 0;//1既不是素数也不是合数
	}
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n = 0,count=0,prime_last=0,prime_now=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (is_prime(i)) {
			prime_last = prime_now;
			prime_now = i;
			if ((prime_now - prime_last == 2)&&prime_last!=0) {//prime_last!=0第一次忘写了，这会判断0、2也是一对
				count++;
			}
		}
	}
	printf("%d", count);
	return 0;
}
