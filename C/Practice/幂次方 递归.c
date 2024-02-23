#include <stdio.h>
#include <math.h>
int n;
void change(int x){
    int m=(int)log2(x);
    if (m==0){
        printf("2(0)");
        return;
    }
    else if(m==1){
        printf("2");
    }
    else {
        printf("2(");
        change(m);
        printf(")");
    }
    x=x-pow(2,m);
    if(x>0) {
        printf("+");
        change(x);
    }
}



int main() {
    scanf("%d",&n);
    change(n);
}

//最多2的14次方
//递归，用简单项试验，思考各种情况的可能，用return省略函数剩下部分！