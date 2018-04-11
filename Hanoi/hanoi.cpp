#include<cstdio>
using namespace std;
void move(int i,char from,char depend,char to){
    if(i==1){
        printf("%c-->%c\n",from,to);
        return ;
    }
    else{
        move(i-1,from,to,depend);
        printf("%c-->%c\n",from,to);
        move(i-1,depend,from,to);
    }
    return ;
}
int main(){
    int n;
    char a='A',b='B',c='C';
    scanf("%d",&n);
    move(n,a,b,c);
    printf("=====over!====\n");
    return 0;
}
