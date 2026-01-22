//1010 一元多项式求导  这道题输入输出上的坑点确实很多，而且输入也不好做，我也是困了，偷个懒直接让AI写的

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int coef, expon;
    int hasOutput = 0; // 标记是否输出过内容

    while (scanf("%d %d", &coef, &expon) != EOF) {
        // 如果指数为0，求导后为0，直接跳过（常数项消失）
        if (expon == 0) continue;

        // 求导运算
        coef = coef * expon;
        expon = expon - 1;

        // 输出控制：如果是第一个输出的，不加空格；否则加空格
        if (hasOutput == 0) {
            printf("%d %d", coef, expon);
            hasOutput = 1; // 标记已经输出了
        }
        else {
            printf(" %d %d", coef, expon);
        }
    }

    // 【补丁逻辑】如果循环结束了，发现一次都没输出过（比如输入 "10 0"）
    if (hasOutput == 0) {
        printf("0 0");
    }

    return 0;
}
//坑有：
// 常数项的处理（指数为 0）
// “零多项式”输出 0 0，需要一个 flag 变量记录“是否输出过内容”。如果循环结束了，flag 还是 false，最后必须补印一个 0 0
//行末不能有空格，由于我们是“读一对、算一对、输出一对”，我们不知道哪一对是最后一对，所以推荐用 “领头空格法”
