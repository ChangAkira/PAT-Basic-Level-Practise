//1004 成绩排名
//这个也很简单咯，我们来练习一下结构体的写法。
#define _CRT_SECURE_NO_WARNINGS 1  //这是为了在VS里使用scanf函数，不知道的同学就不用管这句

#include <stdio.h>
#include <string.h>

int main() {
	int n;
	struct student_infos {
		char name[11];
		char num[11];
		int grade;
	}student_high,student_low,student_temp;
	scanf("%d", &n);
	student_high.grade = -1;
	student_low.grade = 101;

	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", student_temp.name,student_temp.num, &student_temp.grade);
		if (student_temp.grade > student_high.grade) {
			strcpy(student_high.name, student_temp.name);  //同类型的结构体变量可以直接赋值，这里可以改为student_high = student_temp;这样的话也就不需要string.h了
			strcpy(student_high.num, student_temp.num);
			student_high.grade = student_temp.grade;
		}
		if (student_temp.grade < student_low.grade) {
			strcpy(student_low.name ,student_temp.name);
			strcpy(student_low.num ,student_temp.num);
			student_low.grade = student_temp.grade;
		}
	}
	printf("%s %s\n%s %s", student_high.name, student_high.num, student_low.name, student_low.num);
	return 0;
}
