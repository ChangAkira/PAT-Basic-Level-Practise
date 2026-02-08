// 1023 组个最小数
// 这题目看着奇奇怪怪的，其实也是贪心算法
// 累了下次继续写吧
// 注意首位不能是0，那我们可以设定首位的优先级为1>2>3>...>0，而其他位的优先级是0>1>2>...>9
// 我想，这两个优先级我们可以用两个strategie数组来存储

// 其实想太复杂了，一个数组足够了

#include <stdio.h>

int main() {
    int strategie1[10] = {}; // 对于首位，1 2 3 4 5 6 7 8 9 0
    int strategie2[10] = {}; // 对于其他位，0 1 2 3 4 5 6 7 8 9
    int a = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);
        if (i == 0) {
            strategie1[9] = a;
        } else {
            strategie1[i - 1] = a;
        }
        strategie2[i] = a;
    }
    for (int i = 0; i < 10; i++) {
        if (strategie1[i] != 0) {
            printf("%d", i + 1);
            strategie1[i]--;
            strategie2[i + 1]--;
            break;
        }
    }
    for (int j = 0; j < 10; j++) {
        while (strategie2[j] != 0) {
            printf("%d", j);
            strategie2[j]--;
        }
    }
    return 0;
}
