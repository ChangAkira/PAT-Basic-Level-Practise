// 1021 个位数统计
// 你懂的
// 写这么多天了这个要是还能写错我真别写了

#include <stdio.h>
#include <string.h>

int main() {
    char arr[1005] = {};
    int num[10] = {};
    scanf("%s", arr);
    for (int i = 0; i < strlen(arr); i++) {
        int t = arr[i] - '0';
        num[t]++;
    }
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (num[i] != 0) {
            if (flag == 0) {
                printf("%d:%d", i, num[i]); // 第一个不换行
                flag = 1;
            } else {
                printf("\n%d:%d", i, num[i]); // 后面的换行
            }
        }
    }
}