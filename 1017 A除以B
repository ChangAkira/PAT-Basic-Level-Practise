//1017 A除以B
//1000位啊，那得字符串模拟除法了。
//我想到了递归，我想维护一个现在的被除数长度，每次把余数放进新的被除数的最高位里（类似出栈入栈）。对的对的，用栈就很好做了。
//那么高位在栈顶，低位在栈底。接收输入以后将数字反着入栈。
//其实都不需要搓一个真的栈，就用接收输入的这个数组模拟就行了，记录好栈顶位置即可。
//哈哈写着写着发现都不用递归，循环即可，刚开始想的很正派，其实都可以简单模拟出来
//但是写完后AI有点瞧不上我的写法😐那我不管了就这样吧

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>

int main() {
	char arr[1005] = {};
	char brr[1005] = {};//存结果的商
	int count = 0;//存商存到哪一位了
	int num = 0;
	scanf("%s %d", arr, &num);
	int a = 0;//栈顶
	int length = strlen(arr);//同时length-1也是栈底
	int c = 0;//一次除法中的被除数
	int d = 0;//一次除法中的余数
	int e = 0;//一次除法中的商
	for (; a != length - 1;) {
		c=arr[a]-'0';
		if (c < num) {
			a++;
			c = c * 10 + arr[a]-'0';
		}
		e = c / num;
		d = c % num;
		arr[a] = d+'0';
		brr[count] = e+'0';
		count++;
		
	}
	d = arr[length - 1]-'0';//最后的余数就是最后一位数
	if (count == 0) {//上面说我有一个测试点通不过就是这里，如果是5/7这样，没有这一部分的话商会直接留空（下面的for循环会全部跳过）
		printf("0");
	}
	for (int temp = 0; temp < count; temp++) {
		printf("%d", brr[temp]-'0');
	}
	printf(" %d", d);
	return 0;
}
