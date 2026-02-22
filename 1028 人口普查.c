//1028 人口普查
//顺序表、qsort
//题目没写全，如果小镇空无一人则只输出0
#define INIT_SIZE 10000
#define INCREASEMENT 2500
#define bool int
#define true 1
#define false 0
#define NO_MORE_SPACES -1

#include<stdio.h>
#include<stdlib.h>

typedef struct Resident{
    char name[10];
    int year;
    int month;
    int day;
}Resident;

typedef struct List{
    Resident* base;
    int capacity;
    int length;
}List;

Resident* initListBase(){
    Resident* base=(List*)malloc(INIT_SIZE*sizeof(Resident));
    if(!base){
        exit(NO_MORE_SPACES);
    }
    return base;
}
bool initList(List* L){
    L->base=initListBase();
    L->capacity=INIT_SIZE;
    L->length=0;
    return true;
}
bool expandCapacity(List* L){
    Resident* newbase=(Resident*)realloc(L->base,(L->capacity+INCREASEMENT)*(sizeof(Resident)));
    if(!newbase){
        exit(NO_MORE_SPACES);
    }
    L->base=newbase;
    L->capacity=L->capacity+INCREASEMENT;
    return true;
}
bool addElem(List *L,Resident resident){
    if(L->capacity==L->length){
        expandCapacity(L);
    }
    *(L->base+L->length)=resident;
    L->length++;
    return true;
}
bool isValid(Resident resident){
    if(resident.year>2014||resident.year<2014-200)  return false;
    if((resident.year==2014&&resident.month>9)||(resident.year==2014-200&&resident.month<9))  return false;
    if((resident.year==2014&&resident.month==9&&resident.day>6)||(resident.year==2014-200&&resident.month==9&&resident.day<6))  return false;
    return true;
}
int compare(const void* a,const void* b){
    Resident* r1=(Resident*)a;
    Resident* r2=(Resident*)b;
    if(r1->year>r2->year){//我们让年长的排在前面
        return 1;
    }
    else if(r1->year<r2->year){//我们让年长的排在前面
        return -1;
    }
    else if(r1->month>r2->month){//我们让年长的排在前面
        return 1;
    }
    else if(r1->month<r2->month){//我们让年长的排在前面
        return -1;
    }
    else if(r1->day>r2->day){//我们让年长的排在前面
        return 1;
    }
    else if(r1->day<r2->day){//我们让年长的排在前面
        return -1;
    }
    else{
        return 0;
    }
}
int main(){
    int cnt=0;
    scanf("%d",&cnt);
    List L;
    initList(&L);
    Resident temp;
    for(int i=0;i<cnt;i++){
        scanf("%s",temp.name);
        scanf("%d/%d/%d",&(temp.year),&(temp.month),&(temp.day));
        if(!isValid(temp)){
            continue;
        }
        addElem(&L,temp);
    }
    if(L.length==0){
        printf("0");
        return 0;
    }
    qsort(L.base,L.length,sizeof(Resident),compare);
    printf("%d %s %s",L.length,L.base->name,(L.base+L.length-1)->name);
    free(L.base);
    return 0;
}