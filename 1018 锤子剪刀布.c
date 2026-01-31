//1018 锤子剪刀布
//这玩意儿简单
/* 我写的很繁琐，纯暴力解
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
*/

//AI给出的方法：(甲 + 1) % 3 == 乙 时，甲赢

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 辅助函数：将字符转换为数字索引
// B -> 0, C -> 1, J -> 2
int change(char c) {
    if (c == 'B') return 0;
    if (c == 'C') return 1;
    if (c == 'J') return 2;
    return -1;
}

int main() {
    int n;
    // 分别记录甲乙赢、平、输的次数
    // times[0]=赢, times[1]=平, times[2]=输
    int jia_res[3] = {0}, yi_res[3] = {0}; 
    
    // 记录甲乙靠哪个手势赢的次数：0-B, 1-C, 2-J
    int jia_hand[3] = {0}, yi_hand[3] = {0};
    
    // 用于最后输出字符的映射表
    char mp[4] = "BCJ"; 

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char c1, c2;
        scanf(" %c %c", &c1, &c2); // 前面的空格处理缓冲区回车
        
        int k1 = change(c1);
        int k2 = change(c2);

        if ((k1 + 1) % 3 == k2) {
            // 甲赢的情况 (根据 B-0, C-1, J-2 的循环克制规律)
            jia_res[0]++; 
            yi_res[2]++;
            jia_hand[k1]++;
        } else if (k1 == k2) {
            // 平局
            jia_res[1]++;
            yi_res[1]++;
        } else {
            // 乙赢 (剩下就是乙赢)
            jia_res[2]++;
            yi_res[0]++;
            yi_hand[k2]++;
        }
    }

    // 输出胜负平数据
    printf("%d %d %d\n", jia_res[0], jia_res[1], jia_res[2]);
    printf("%d %d %d\n", yi_res[0], yi_res[1], yi_res[2]);

    // 寻找赢次最多的手势
    // 因为我们是按 B(0), C(1), J(2) 的顺序遍历
    // 所以只要找最大值，不严格大于就不更新，自然满足“字母序最小”
    int id1 = 0, id2 = 0;
    for (int i = 0; i < 3; i++) {
        if (jia_hand[i] > jia_hand[id1]) id1 = i;
        if (yi_hand[i] > yi_hand[id2]) id2 = i;
    }

    printf("%c %c", mp[id1], mp[id2]);
    
    return 0;
}
