//这道题有三个核心：1、字符串组成的数组怎么写    2、输入的数这么大，应该用字符串接收    3、字符串与数字互转
#define _CRT_SECURE_NO_WARNINGS 1  //这是为了在VS里使用scanf函数，不知道的同学就不用管这句

#include <stdio.h>
#include <string.h>

const char* arr[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};  //要定义为const，因为字符串在C语言里是不能通过指针指向来修改的


int main(){
    char input[101] = {0};
    int sum = 0;
    scanf("%s", input);
    int input_len = strlen(input);
    for (int i = 0; i < input_len; i++) {
        sum += input[i]-48;  //ascll码值  
      //写成sum += (input[i] - '0');更好读呢
    }
    /*有更好的方法，这是原来我写的
    int output[101];
    memset(output, -1, sizeof(output));  //初始化output全为-1，用这种方法只能做到全赋值为-1或0，想初始化其它还是使用for循环。该函数头文件为string.h
    for (int i = 0;; i++) {  //这一段把sum数字转为output数组（反着的）
        int t = sum % 10;
        sum = (sum - t) / 10;
        output[i] = t;
        if (sum < 10) {
            if (sum != 0) {  //如输入12，和为3，则最后一次sum值为0，如果不加这个判断条件，最后会输出“ling san”，如果注意不到这点会有一个测试点不通过
                output[i + 1] = sum;
            }
            break;
        }
    }
    int i = 0;
    for (;output[i]!=-1; i++) {  //因为上面转为数组是反着的，所以我们先看一下究竟多少位吧，这也是初始化为-1的原因

    }
    for (int t = i - 1; t > 0; t--) {  //然后就可以倒着输出了，这里不输出最后一位因为最后一位不要空格
        printf("%s ", arr[output[t]]);
    }
    printf("%s", arr[output[0]]);  //最后一位不要空格，单独输出一下
    */
    //更好的方法：可以通过 sprintf 将 sum 直接转回字符串
    char s[101];  //给多少位比较合适呢？
    sprintf(s, "%d", sum);

    int s_len = strlen(s);
    for (int i = 0; i < s_len; i++) {
        // 将字符转回数字索引，s[i]-'0'
        printf("%s", arr[s[i] - '0']);
        
        // 如果不是最后一位，输出空格
        if (i < s_len - 1) {
            printf(" ");
        }
    }
    return 0;
}

