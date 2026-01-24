//1013 数素数
//如果真碰上这样的题那我可要从网上找个素数表了
//简单地讲我们这样试除法就可以了，判断素数还有更好的埃氏筛、线性筛之类的。这里只写试除法。

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>

int is_prime(int num) {//从1007 素数对猜想复制过来的
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

	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0, count = 0; count <= n; i++) {
		if (is_prime(i)) {
			if (count >= m) {
				printf("%d", i);
				if ((count - m + 1) % 10 == 0) {
					printf("\n");
				}
				else {
					if (count != n) {
						printf(" ");
					}
				}
				
			
			}
			count++;
		}
		else {

		}

	}

	return 0;
}
