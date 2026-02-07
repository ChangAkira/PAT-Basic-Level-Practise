// 1020 月饼
//  很明显的部分背包问题，贪心算法
//  这边我们还是练习结构体数组的动态分配
//  快到睡觉时间了明天再写吧hh

// 我回来了。这一次尝试写得标准漂亮一点。

#define _ERROR_NO_MORE_SPACES_ -1
#define _INITSIZE_ 100
#define _INCREASEMENT_ 20
#define bool int
#define true 1

#include <stdio.h>
#include <stdlib.h>

typedef struct Mooncake {
    double quantity; // 题目只说是正数，没说是整数
    double profits;
    double q; // 性价比
} Mooncake;

bool addMooncakes(Mooncake **mooncakes, int *capacity) { // 指针有变化，需要传入指针的指针
    Mooncake *newbase = (Mooncake *)realloc(*mooncakes, (*capacity + _INCREASEMENT_) * sizeof(Mooncake));
    if (!newbase) {
        exit(_ERROR_NO_MORE_SPACES_);
    }
    *mooncakes = newbase;
    *capacity += _INCREASEMENT_;
    // free(newbase);不行！newbase现在和*mooncakes指向同一块儿空间，free以后*mooncakes指向的也没了
    return true;
}

int compare(const void *a, const void *b) {
    if (((Mooncake *)b)->q - ((Mooncake *)a)->q > 0) {
        return 1;
    } else if (((Mooncake *)b)->q - ((Mooncake *)a)->q < 0) {
        return -1;
    } else {
        return 0;
    }
    // 我们要的是从大到小排序
}

int main() {
    Mooncake *mooncakes = (Mooncake *)malloc(_INITSIZE_ * sizeof(Mooncake));
    int marketneed;
    int types; // 月饼种类数，其实也就是需要的结构体数
    int capacity = _INITSIZE_;
    int length = 0;
    double selected_quantity = 0;
    double result_profits = 0;
    scanf("%d %d", &types, &marketneed);
    for (int i = 0; i < types; i++) {
        if (length + 1 > capacity) {
            addMooncakes(&mooncakes, &capacity);
        }
        scanf("%lf", &(mooncakes[i].quantity));
        length++;
    }
    for (int i = 0; i < types; i++) {
        scanf("%lf", &(mooncakes[i].profits));
        mooncakes[i].q = mooncakes[i].profits / mooncakes[i].quantity;
    }
    qsort(mooncakes, types, sizeof(Mooncake), compare);
    int nowneed;
    for (int select_pos = 0; select_pos < types; select_pos++) {
        nowneed = marketneed - selected_quantity;
        if (nowneed > 0) {                                  // 还能装
            if (mooncakes[select_pos].quantity < nowneed) { // 可以全部卖出
                selected_quantity += mooncakes[select_pos].quantity;
                result_profits += mooncakes[select_pos].profits * 1.0;
            } else { // 这个再装点，然后退出循环
                result_profits += mooncakes[select_pos].q * (nowneed) * 1.0;
                break;
            }
        } else {
            // 别装了，这里应该是正好
            break;
        }
    }

    printf("%.2lf", result_profits);
    free(mooncakes);
    return 0;
}