// 1022 D进制的A+B
// 哦买噶，任意进制互转，我记得最开始学C语言就写了这个，可是现在完全忘记了

// 到现在学了这么久C语言，这里我们用比较好的解法吧，来练习一下栈的写法。

#define _INITSIZE_ 30
#define _INCREASEMENT_ 5
#define bool int
#define true 1
#define _NO_MORE_SPACES_ -1

#include <stdio.h>
#include <stdlib.h>

void add_stack(long long **stack_bottom, long long *capacity) {
    long long *newbase = (long long *)realloc(*stack_bottom, (*capacity + _INCREASEMENT_) * sizeof(long long));
    if (!newbase) {
        exit(_NO_MORE_SPACES_);
    }
    *stack_bottom = newbase;
    *capacity += _INCREASEMENT_;
}

void stack_push(long long **stack_bottom, long long **stack_top, long long r, long long *capacity, long long *used) {
    if (*used == *capacity) {
        add_stack(stack_bottom, capacity);
        *stack_top = *stack_bottom + (*used);
    }
    (**stack_top) = r;
    (*stack_top)++;
    (*used)++;
}

int main() {
    int a, b;
    int c;
    long long stack_capacity, stack_used;
    long long *stack_bottom = (long long *)malloc(_INITSIZE_ * sizeof(long long));
    stack_capacity = _INITSIZE_;
    long long *stack_top = stack_bottom;
    stack_used = 0;
    scanf("%d %d %d", &a, &b, &c);
    long long t = a + b;
    while (t != 0) {
        long long r = t % c;
        stack_push(&stack_bottom, &stack_top, r, &stack_capacity, &stack_used);
        t = t / c;
    }
    if (stack_top == stack_bottom) {//这儿有个边界条件，不加的话有一个测试用例通不过
        printf("0");
        return 0;
    }
    while (stack_top != stack_bottom) {
        stack_top--;
        printf("%lld", *stack_top);
    }
    free(stack_bottom);
    return 0;
}
//从大一前的暑假拼死拼活用数组搞不出动态扩容+倒着输出，到现在几十行代码手搓栈，我用了四年/(ㄒoㄒ)/~~