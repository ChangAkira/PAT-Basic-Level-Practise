// 1034 有理数四则运算

#define bool int
#define true 1
#define false 0

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct rationalNumbers {
    bool negFlag;
    bool fullFlag; // 如果整数部分和分数部分都有，这个flag为1，一会儿打印时中间要有个空格
    long long partA;
    long long partB;
    long long partC;
} rationalNumbers;

long long gcd(long long a, long long b) { // 求最大公约数
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

void simplifyd(rationalNumbers *number) {
    long long gcdNum = gcd(number->partB, number->partC);
    number->partB /= gcdNum;
    number->partC /= gcdNum;
    long long addPartA = number->partB / number->partC;
    number->partB = number->partB % number->partC;
    number->partA += addPartA;
    return;
}

void inputNumber(rationalNumbers *number) {
    // 先用 * 解引用拿到实体，然后直接塞给它一个全为 0 的匿名结构体
    *number = (rationalNumbers){0};
    number->partA = 0;
    scanf("%lld/%lld", &number->partB, &number->partC);
    if (number->partB < 0) {
        number->partB = llabs(number->partB);
        number->negFlag = true;
    }
    simplifyd(number);
    if (number->partA != 0 && number->partB != 0) {
        number->fullFlag = true;
    }
    return;
}

void outputNumber(rationalNumbers number) {
    if (number.partA == 0 && number.partB == 0) {
        printf("0");
        return;
    }
    if (number.negFlag) {
        printf("(-");
    }
    if (number.partA != 0) {
        printf("%lld", number.partA);
    }
    if (number.fullFlag) {
        printf(" ");
    }
    if (number.partB != 0) {
        printf("%lld/%lld", number.partB, number.partC);
    }
    if (number.negFlag) {
        printf(")");
    }
    return;
}

rationalNumbers addition(rationalNumbers *number1, rationalNumbers *number2) {
    rationalNumbers result;
    result.partA =
}