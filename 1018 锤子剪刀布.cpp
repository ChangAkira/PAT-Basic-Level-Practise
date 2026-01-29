//1018 锤子剪刀布
//这玩意儿简单
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
int main() {
	int jia_win = 0, yi_win = 0;
	int jia_lose = 0, yi_lose = 0;
	int jia_ping = 0, yi_ping = 0;
	int jia_win_B = 0, yi_win_B = 0;
	int jia_win_C = 0, yi_win_C = 0;
	int jia_win_J = 0, yi_win_J = 0;
	char this_jia, this_yi;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %c %c", &this_jia, &this_yi);//在格式串开头加空格的方式来跳过空白符和换行符

		switch (this_jia) {
		case 'B':
			switch (this_yi) {
			case 'B':
				jia_ping++;
				yi_ping++;
				break;
			case 'C':
				jia_win++;
				yi_lose++;
				jia_win_B++;
				break;
			case 'J':
				yi_win++;
				jia_lose++;
				yi_win_J++;
				break;
			}
			break;
		case 'C':
			switch (this_yi) {
			case 'B':
				jia_lose++;
				yi_win++;
				yi_win_B++;
				break;
			case 'C':
				jia_ping++;
				yi_ping++;
				break;
			case 'J':
				yi_lose++;
				jia_win++;
				jia_win_C++;
				break;
			}
			break;
		case 'J':
			switch (this_yi) {
			case 'B':
				jia_win++;
				jia_win_J++;
				yi_lose++;
				break;
			case 'C':
				jia_lose++;
				yi_win++;
				yi_win_C++;
				break;
			case 'J':
				yi_ping++;
				jia_ping++;
				break;
			}
			break;
		}
			
	}
	printf("%d %d %d\n%d %d %d\n", jia_win, jia_ping, jia_lose, yi_win, yi_ping, yi_lose);
	char jia_win_most = 'J';
	char yi_win_most = 'J';//初始化为J倒着查自然就能按字母序了
	int temp = 0;
	temp = jia_win_J;
	if(temp<=jia_win_C){
		temp = jia_win_C;
		jia_win_most = 'C';
	}
	if(temp<=jia_win_B){
		temp = jia_win_B;
		jia_win_most = 'B';
	}
	temp = yi_win_J;
	if(temp<=yi_win_C){
		temp = yi_win_C;
		yi_win_most = 'C';
	}
	if(temp<=yi_win_B){
		temp = yi_win_B;
		yi_win_most = 'B';
	}


	printf("%c %c", jia_win_most, yi_win_most);
	return 0;
}
