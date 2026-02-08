// 1022 D进制的A+B
// 哦买噶，任意进制互转，我记得最开始学C语言就写了这个，可是现在完全忘记了

// 到现在学了这么久C语言，这里我们用比较好的解法吧，来练习一下栈的写法。

// #define _INITSIZE_ 30
// #define _INCREASEMENT_ 5
// #define bool int
// #define true 1
// #define _NO_MORE_SPACES_ -1

// #include <stdio.h>
// #include <stdlib.h>

// void add_stack(long long **stack_bottom, long long *capacity) {
//     long long *newbase = (long long *)realloc(*stack_bottom, (*capacity + _INCREASEMENT_) * sizeof(long long));
//     if (!newbase) {
//         exit(_NO_MORE_SPACES_);
//     }
//     *stack_bottom = newbase;
//     *capacity += _INCREASEMENT_;
// }

// void stack_push(long long **stack_bottom, long long **stack_top, long long r, long long *capacity, long long *used) {
//     if (*used == *capacity) {
//         add_stack(stack_bottom, capacity);
//         *stack_top = *stack_bottom + (*used);
//     }
//     (**stack_top) = r;
//     (*stack_top)++;
//     (*used)++;
// }

// int main() {
//     int a, b;
//     int c;
//     long long stack_capacity, stack_used;
//     long long *stack_bottom = (long long *)malloc(_INITSIZE_ * sizeof(long long));
//     stack_capacity = _INITSIZE_;
//     long long *stack_top = stack_bottom;
//     stack_used = 0;
//     scanf("%d %d %d", &a, &b, &c);
//     long long t = a + b;
//     while (t != 0) {
//         long long r = t % c;
//         stack_push(&stack_bottom, &stack_top, r, &stack_capacity, &stack_used);
//         t = t / c;
//     }
//     if (stack_top == stack_bottom) {//这儿有个边界条件，不加的话有一个测试用例通不过
//         printf("0");
//         return 0;
//     }
//     while (stack_top != stack_bottom) {
//         stack_top--;
//         printf("%lld", *stack_top);
//     }
//     free(stack_bottom);
//     return 0;
// }
// 从大一前的暑假拼死拼活用数组搞不出动态扩容+倒着输出，到现在几十行代码手搓栈，我用了四年/(ㄒoㄒ)/~~

// 我突然想起来，在1009中，我们利用了函数的递归调用时天然提供给我们的栈。我们可以试试这种写法。

#define status int
#define have_output 1
#define no_output 0

#include <stdio.h>
#include <stdlib.h>

// 这是我原来写的
status func(long long t, int c) {
    // 除以一个int，余数肯定小于int，用int就行
    if (t == 0) {
        return no_output; // 如果第一层就要返回，也就是主函数中输入t即为0，返回没有输出
    }
    int q = t % c;
    func(t / c, c);
    printf("%d", q);
    return have_output; // 只要超过一层，肯定有输出
}

// 还可以更简洁
void func2(long long t, int c) {
    if (t / c != 0) {
        func2(t / c, c); // 只要商还没到0，就继续往深处走
    }
    printf("%lld", t % c); // 回溯时打印余数
}

int main() {
    int a, b;
    int c;
    scanf("%d %d %d", &a, &b, &c);
    long long t = a + b;

    // 这是用原来的写法1
    //  if(!func(t, c)){
    //      printf("0");//否则一个样例通不过
    //  }

    func2(t, c);

    return 0;
}

// 哦买噶，这样写竟然这么简单，我牛大了