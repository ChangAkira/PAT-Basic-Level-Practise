// 1034 有理数四则运算
// 这道题真的汗流浃背了

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

rationalNumbers simplifyd(rationalNumbers number) { // 不化简直接计算，计算时带符号算。输出前化简，化简包括取绝对值，输出符号由标志位控制
    number.partA = llabs(number.partA);
    number.partB = llabs(number.partB);
    number.partC = llabs(number.partC);
    long long gcdNum = gcd(number.partB, number.partC);
    number.partB /= gcdNum;
    number.partC /= gcdNum;
    long long addPartA = number.partB / number.partC;
    number.partB = number.partB % number.partC;
    number.partA += addPartA;
    if (number.partA != 0 && number.partB != 0) {
        number.fullFlag = true;
    }
    return number;
}

void inputNumber(rationalNumbers *number) {
    number->partA = 0;
    scanf("%lld/%lld", &number->partB, &number->partC);
    if (number->partB < 0) {
        // number->partB = llabs(number->partB);
        number->negFlag = true;
    }
    return;
}

void outputNumber(rationalNumbers number) {
    number = simplifyd(number);
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

void addition(rationalNumbers number1, rationalNumbers number2) {
    rationalNumbers result = {false, false, 0, 0, 0};
    result.partC = number1.partC * number2.partC;
    result.partB = number1.partB * number2.partC + number2.partB * number1.partC;
    if (result.partB < 0) {
        result.negFlag = true;
    }
    outputNumber(number1);
    printf(" + ");
    outputNumber(number2);
    printf(" = ");
    outputNumber(result);
    return;
}

void subtraction(rationalNumbers number1, rationalNumbers number2) {
    rationalNumbers result = {false, false, 0, 0, 0};
    result.partC = number1.partC * number2.partC;
    result.partB = number1.partB * number2.partC - number2.partB * number1.partC;
    if (result.partB < 0) {
        result.negFlag = true;
    }
    outputNumber(number1);
    printf(" - ");
    outputNumber(number2);
    printf(" = ");
    outputNumber(result);
    return;
}
void multiplication(rationalNumbers number1, rationalNumbers number2) {
    rationalNumbers result = {false, false, 0, 0, 0};
    result.partC = number1.partC * number2.partC;
    result.partB = number1.partB * number2.partB;
    if (result.partB < 0) {
        result.negFlag = true;
    }
    outputNumber(number1);
    printf(" * ");
    outputNumber(number2);
    printf(" = ");
    outputNumber(result);
    return;
}
void division(rationalNumbers number1, rationalNumbers number2) {
    if (number2.partA == 0 && number2.partB == 0) {
        outputNumber(number1);
        printf(" / ");
        outputNumber(number2);
        printf(" = Inf");
        return;
    }
    rationalNumbers result = {false, false, 0, 0, 0};
    result.partC = number1.partC * number2.partB;
    result.partB = number1.partB * number2.partC;
    if ((result.partC < 0 && result.partB > 0) || (result.partC > 0 && result.partB < 0)) {
        result.negFlag = true;
    }
    outputNumber(number1);
    printf(" / ");
    outputNumber(number2);
    printf(" = ");
    outputNumber(result);
    return;
}

int main() {
    rationalNumbers number1 = {false, false, 0, 0, 0};
    rationalNumbers number2 = {false, false, 0, 0, 0};
    inputNumber(&number1);
    inputNumber(&number2);
    addition(number1, number2);
    printf("\n");
    subtraction(number1, number2);
    printf("\n");
    multiplication(number1, number2);
    printf("\n");
    division(number1, number2);

    return 0;
}