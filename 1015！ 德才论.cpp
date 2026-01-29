//1015 德才论
//这又是什么神经题目啊，俺真不中嘞
//这道题里我才真正会用了qsort。以前没咋用过qsort函数，这玩意儿这么好用？！！还能自定义排序规则！那我以前写C语言手写冒泡排序快速排序算什么哈哈

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student {
	int num;
	int de;
	int cai;
	int type;// 1德才兼备  2才分不到但德分到  3“才德兼亡”但尚有“德胜才”  4其它 
	int sum;

}student;

int compare(const void* a, const void* b) {
	student* s1 = (student*)a;
	student* s2 = (student*)b;
	if (s1->type != s2->type) {
		return s1->type - s2->type;
	}
	else if (s1->sum != s2->sum) {//同类型看总分
		return s2->sum - s1->sum;
	}
	else if (s1->de != s2->de) {//同总分看德分
		return s2->de - s1->de;
	}
	else {//同德分看考号
		return s1->num - s2->num;
	}
}

int main() {
	int n = 0,l=0,h=0;
	scanf("%d%d%d", &n, &l, &h);
	student* students = (student*)malloc(n * sizeof(student));
	int count = 0;//有资格人数，排序时要传入
	int num, de, cai;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d\n", &num,&de,&cai);
		
		if (de < l||cai < l) {

		}
		else {
			students[count].de = de;
			students[count].cai = cai;
			students[count].num = num;
			students[count].sum = students[count].de+ students[count].cai;

			if ((students[count].de >= h) && (students[count].cai >= h)) {
				students[count].type = 1;
			}
			else if ((students[count].de >= h) && (students[count].cai < h)) {
				students[count].type = 2;
			}
			else if ((students[count].de >= students[count].cai)) {
				students[count].type = 3;
			}
			else {
				students[count].type = 4;
			}
			count++;
		}
	}
	qsort(students, count, sizeof(student), compare);
	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d %d %d", students[i].num, students[i].de, students[i].cai);
			if (i != count - 1) {
				printf("\n");
		}
	}

	return 0;
}
