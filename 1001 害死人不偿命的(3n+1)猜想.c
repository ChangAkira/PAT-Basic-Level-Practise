//这道题很简单咯
int main(){
    int n=-1;
    int i=0;
    scanf("%d",&n);
    for(i=0;n!=1;i++){
        if(n%2==0){
            n=n/2;
        }
        else{
            n=(3*n+1)/2;
        }
    }
    printf("%d",i);
    return 0;
}
