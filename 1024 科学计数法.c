// 1024 科学计数法
// 不管那么多，来可变长顺序表练习
// 这也太绕了！是我的思路有问题吗？应该直接切成两段做比较简单吧，我这里写的方法是真的在模拟让小数点移动！
#define INIT_SIZE 500
#define INCREASE_SIZE 100
#define bool int
#define true 1
#define false 0
#define NO_MORE_SPACES -1
#define ELEMTYPE char

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    ELEMTYPE *baseptr;
    int capacity;
    int length;
} List;

bool initList(List *L) {
    ELEMTYPE *temp = (ELEMTYPE *)malloc(INIT_SIZE * (sizeof(ELEMTYPE)));
    if (!temp) {
        exit(NO_MORE_SPACES);
    }
    L->baseptr = temp;
    L->capacity = INIT_SIZE;
    L->length = 0;
    return true;
}

bool expandCapacity(List *L) {

    ELEMTYPE *newbaseptr = (ELEMTYPE *)realloc(L->baseptr, (L->capacity + INCREASE_SIZE) * sizeof(ELEMTYPE));
    if (!newbaseptr) {
        exit(NO_MORE_SPACES);
    }
    L->baseptr = newbaseptr;
    L->capacity = L->capacity + INCREASE_SIZE;
    return true;
}

bool addElem(List *L, ELEMTYPE a) {

    if (L->length == L->capacity) {
        expandCapacity(L);
    }
    *(L->baseptr + L->length) = a;
    L->length++;
    return true;
}

int main() {
    List *Lin = (List *)malloc(sizeof(List));
    List *Lout = (List *)malloc(sizeof(List));
    List *Ltemp = (List *)malloc(sizeof(List));
    initList(Lin);
    initList(Lout);
    initList(Ltemp);
    char a;
    int Epos = 0;
    int flag = 0;
    while ((a = getchar()) != '\n') {
        addElem(Lin, a);
        if (flag) {
            addElem(Ltemp, a);
        }
        if (a == 'E') {
            Epos = Lin->length;
            flag = 1;
        }
    }
    if (*(Lin->baseptr) == '-') {
        addElem(Lout, '-');
    }
    int Ep = 0;
    // 题目已经说了数字的整数部分只有一位，那么小数点肯定是在baseptr+2的地方。E的位置已经找到，E后面的部分也已经拿到
    for (int i = 1; i < Ltemp->length; i++) {
        Ep = Ep * 10 + (*(Ltemp->baseptr + i) - '0');
    }
    if (*(Ltemp->baseptr) == '-') {
        Ep = -Ep;
    }
    // 我们可以求小数点现在应该在那个整数位置的相对位置。
    // 如果指数是2，那就是小数点后移两位，小数点变成baseptr+4的位置
    // 如果指数是-2，那就是小数点前移两位，小数点变成baseptr的位置
    char *dotPos = Lin->baseptr + 2 + Ep;
    if (dotPos <= Lin->baseptr + 1) {
        addElem(Lout, '0');
        addElem(Lout, '.');
        dotPos++;
        while (dotPos <= Lin->baseptr + 1) {
            addElem(Lout, '0');
            dotPos++;
        }
        for (int i = 1; i < Epos - 1; i++) {
            if (i == 2) {
                continue;
            }
            addElem(Lout, *(Lin->baseptr + i));
        }
    } else {
        int flag2 = 0;
        addElem(Lout, *(Lin->baseptr + 1));
        int i = 3;
        for (i = 3; dotPos >= Lin->baseptr + i; i++) {
            if (*(Lin->baseptr + i) == 'E') {
                flag2 = 1;
            }
            if (flag2) {
                addElem(Lout, '0');
            } else {
                addElem(Lout, *(Lin->baseptr + i));
            }
        }
        if (i < Epos - 1) {
            addElem(Lout, '.');
        }

        for (; i < Epos - 1; i++) {
            addElem(Lout, *(Lin->baseptr + i));
        }
    }

    for (int i = 0; i < Lout->length; i++) {
        printf("%c", *(Lout->baseptr + i));
    }
    free(Lin->baseptr);
    free(Lout->baseptr);
    free(Ltemp->baseptr);
    free(Lin);
    free(Lout);
    free(Ltemp);
    return 0;
}