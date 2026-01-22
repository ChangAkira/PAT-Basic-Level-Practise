//1008 数组元素循环右移问题
//考虑程序移动数据的次数尽量少，如果学过操作系统，那知道用链表比较好了，不过对于这道题而言，直接用数组下标做计算更简单。先写一下用数组下标的
//再写一下链表的，一般的链表和循环链表都可以
//最后，AI还告诉我一个三步翻转法

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	int n = 0, m = 0;
//	scanf("%d %d", &n,&m);
//	int nums[101] = {};
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &nums[i]);
//	}
//	for (int i = n-m; i < n; i++) {
//		printf("%d ", nums[i]);
//	}
//	for (int i = 0; i < n-m; i++) {
//		printf("%d", nums[i]);
//		if (i != n-m-1) {
//			printf(" ");
//		}
//	}
//	return 0;
//}

//然后部分正确。问了下AI。
//这是一个非常经典的“坑”，你的代码思路其实非常巧妙（既然题目只要求输出，我就不需要真的在内存里移动数据，直接按顺序打印即可），这在竞赛中被称为“逻辑作弊”或“假动”，是完全可行的解法。导致部分测试点错误的核心原因只有一个：忽略了 M 可能大于 N 的情况。

//好吧，改一下

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main() {
//	int n = 0, m = 0;
//	scanf("%d %d", &n, &m);
//	m = m % n;//在读取输入后，立刻对 M 进行取模运算，去掉多余的整圈移动。原来是这样！
//	int nums[101] = {};
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &nums[i]);
//	}
//	for (int i = n - m; i < n; i++) {
//		printf("%d ", nums[i]);
//	}
//	for (int i = 0; i < n - m; i++) {
//		printf("%d", nums[i]);
//		if (i != n - m - 1) {
//			printf(" ");
//		}
//	}
//	return 0;
//}

//接下来来练习一下链表写法。

//首先是一般的链表写法。下面的循环链表写法可能还会更简单。

//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<stdlib.h>
//typedef struct LNode {
//	int data;
//	struct LNode* next;
//} LNode;
//
//int main() {
//	int n = 0, m = 0;
//	scanf("%d %d", &n, &m);
//	m = m % n;//在读取输入后，立刻对 M 进行取模运算，去掉多余的整圈移动
//	
//	//构建链表通常需要三个指针：head：永远指向链表的头，不能动（否则找不到链表了）。newNode：用来每次申请新的节点。tail（尾指针）：永远指向链表当前的最后一个节点，方便把新节点接在后面。
//	LNode* head = NULL; // 链表头
//	LNode* tail = NULL; // 链表尾，用来不断往后接
//
//    for (int i = 0; i < n; i++) {
//        // 1. 先申请内存
//        LNode* newNode = (LNode*)malloc(sizeof(LNode));
//
//        // 2. 再读取数据
//        scanf("%d", &newNode->data); // 注意这里要用 &，因为 data 是 int
//        newNode->next = NULL;        // 新节点的 next 暂时指向空
//
//        // 3. 把节点连入链表
//        if (head == NULL) {
//            // 如果这是第一个节点，它既是头也是尾
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            // 如果不是第一个节点
//            tail->next = newNode; // 1. 让原来的尾巴指向新节点
//            tail = newNode;       // 2. 更新尾巴，让新节点成为新的尾巴
//        }
//    }
//
//    //画个草图看一眼……比如说6个数右移2位……那就是输出5、6，然后从头输出1234.
//    LNode *printnode=head;
//    for (int i = 0; i < n - m; i++) {
//        printnode = printnode->next;
//    }
//    while (printnode->next != NULL) {
//        printf("%d ", printnode->data);
//        printnode = printnode->next;
//    }
//    printf("%d ", printnode->data);//最后一个
//    printnode = head;
//    for (int i = 1; i < n - m; i++) {//有一个不要空格所以这里循环少一次
//        printf("%d ", printnode->data);
//        printnode = printnode->next;
//    }
//    printf("%d", printnode->data);//这个不要空格
//	return 0;
//}
//部分正确，提示段错误，问过AI：没有处理 m = 0 （或者 m 是 n 的倍数）的情况。当 m = 0 时，程序会试图访问空指针（NULL），从而导致崩溃。
//假设输入 n = 6, m = 6。 经过 m = m % n 后，m 变成了 0。 此时 n - m 等于 6。
//for (int i = 0; i < n - m; i++) {这里printnode 从头开始走了 6 步，最后指向了 NULL
//紧接着下一句：while (printnode->next != NULL)试图访问 NULL->next

//修改：加入如果在 m = m % n; 之后m==0，原样输出
//或者加入如果printnode==NULL，则printnode=head，但是这会输出两次，这儿就不赘述了，可以自己看一眼为什么
//所以下面写第一种修改办法


//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<stdlib.h>
//typedef struct LNode {
//    int data;
//    struct LNode* next;
//} LNode;
//
//int main() {
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//    m = m % n;//在读取输入后，立刻对 M 进行取模运算，去掉多余的整圈移动
//
//    //构建链表通常需要三个指针：head：永远指向链表的头，不能动（否则找不到链表了）。newNode：用来每次申请新的节点。tail（尾指针）：永远指向链表当前的最后一个节点，方便把新节点接在后面。
//    LNode* head = NULL; // 链表头
//    LNode* tail = NULL; // 链表尾，用来不断往后接
//
//    for (int i = 0; i < n; i++) {
//        // 1. 先申请内存
//        LNode* newNode = (LNode*)malloc(sizeof(LNode));
//
//        // 2. 再读取数据
//        scanf("%d", &newNode->data); // 注意这里要用 &，因为 data 是 int
//        newNode->next = NULL;        // 新节点的 next 暂时指向空
//
//        // 3. 把节点连入链表
//        if (head == NULL) {
//            // 如果这是第一个节点，它既是头也是尾
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            // 如果不是第一个节点
//            tail->next = newNode; // 1. 让原来的尾巴指向新节点
//            tail = newNode;       // 2. 更新尾巴，让新节点成为新的尾巴
//        }
//    }
//
//    LNode* printnode = head;//这个需要提前
//
//    if (m == 0) {//加入部分
//        while (printnode != tail) {//用一下tail哈哈，最后一个不要空格
//            printf("%d ", printnode->data);
//            printnode = printnode->next;
//        }
//        printf("%d", printnode->data);
//        return 0;//一定记得这里要return了
//    }
//
//    //画个草图看一眼……比如说6个数右移2位……那就是输出5、6，然后从头输出1234.
//    
//    for (int i = 0; i < n - m; i++) {
//        printnode = printnode->next;
//    }
//
//    while (printnode->next != NULL) {
//        printf("%d ", printnode->data);
//        printnode = printnode->next;
//    }
//    printf("%d ", printnode->data);//最后一个
//    printnode = head;
//    for (int i = 1; i < n - m; i++) {//有一个不要空格所以这里循环少一次
//        printf("%d ", printnode->data);
//        printnode = printnode->next;
//    }
//    printf("%d", printnode->data);//这个不要空格
//    return 0;
//}

//接下来练习下循环链表的方法
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include<stdlib.h>
//typedef struct LNode {
//    int data;
//    struct LNode* next;
//} LNode;
//
//int main() {//前面是一样的
//    int n = 0, m = 0;
//    scanf("%d %d", &n, &m);
//    m = m % n;//在读取输入后，立刻对 M 进行取模运算，去掉多余的整圈移动
//
//    //构建链表通常需要三个指针：head：永远指向链表的头，不能动（否则找不到链表了）。newNode：用来每次申请新的节点。tail（尾指针）：永远指向链表当前的最后一个节点，方便把新节点接在后面。
//    LNode* head = NULL; // 链表头
//    LNode* tail = NULL; // 链表尾，用来不断往后接
//
//    for (int i = 0; i < n; i++) {
//        // 1. 先申请内存
//        LNode* newNode = (LNode*)malloc(sizeof(LNode));
//
//        // 2. 再读取数据
//        scanf("%d", &newNode->data); // 注意这里要用 &，因为 data 是 int
//        newNode->next = NULL;        // 新节点的 next 暂时指向空
//
//        // 3. 把节点连入链表
//        if (head == NULL) {
//            // 如果这是第一个节点，它既是头也是尾
//            head = newNode;
//            tail = newNode;
//        }
//        else {
//            // 如果不是第一个节点
//            tail->next = newNode; // 1. 让原来的尾巴指向新节点
//            tail = newNode;       // 2. 更新尾巴，让新节点成为新的尾巴
//        }
//    }
//    //然后把tail的next指向head就是循环链表咯
//    tail->next = head;
//    //然后从第n-m个结点开始，连续输出n个即可
//    LNode* printnode = head;
//    for (int i = 0; i < n - m; i++) {
//        printnode = printnode->next;
//    }
//    for (int i = 0; i < n-1; i++) {
//        printf("%d ", printnode->data);
//        printnode = printnode->next;
//    }
//    printf("%d", printnode->data);
//
//    return 0;
//}//比起一般的链表竟然简单了这么多！！！
//最后是AI告诉我的三次翻转法，它是这么说的：
/*
翻转整个数组：6 5 4 3 2 1
翻转前 M 个数（翻转 6 5）：5 6 4 3 2 1
翻转剩余 N-M 个数（翻转 4 3 2 1）：5 6 1 2 3 4 
*/
//我们来试着实现一下。注意题目要求不能有额外数组。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swapArr(int nums[], int begin_n, int end_n) {
	for (int i = 0; i < (end_n - begin_n + 1) / 2; i++) {//加1是因为，比如6个数翻转，传入开始位置0，结束位置5，(5-0)/2得到2了，但应该是3
		int temp = nums[begin_n+i];
		nums[begin_n + i] = nums[end_n - i];
		nums[end_n - i] = temp;
	}
}
int main() {
	int nums[101] = {};
	int n = 0, m = 0;
    scanf("%d %d", &n, &m);
	m = m % n;//在读取输入后，立刻对 M 进行取模运算，去掉多余的整圈移动
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	
	swapArr(nums,0,n-1);
	swapArr(nums, 0, m-1);
	swapArr(nums, m, n - 1);
	int j = 0;
	for (; j < n-1; j++) {
		printf("%d ", nums[j]);
	}
	printf("%d", nums[j]);
	return 0;
}
//这样确实好简单！

//AI看了我的代码以后也很高兴。不过它提出了更好读的意见：使用双指针

//void swapArr(int nums[], int left, int right) {
//    // 只要左边小于右边，就一直交换并向中间走
//    while (left < right) {
//        int temp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = temp;
//
//        left++;  // 左边往右走
//        right--; // 右边往左走
//    }
//}

//这样可以少写一些算术表达式，减少大脑运算量。的确，这是个好方法
