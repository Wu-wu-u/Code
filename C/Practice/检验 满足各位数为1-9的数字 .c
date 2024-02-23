#include <stdio.h>
int a[10],sum=0,b,c,flag=1;
int sort(){
    int temp;
    for(int i=1;i<=9;i++){
        for (int j=1;j<=8;j++){
            if(a[j]>a[j+1]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
            else if(a[j]==a[j+1]){
                flag=0;
                return flag;
            }
        }
    }
}

int main() {
    for(int i=192;i<=329;i++){
        sum=0;
        b=2*i;
        c=3*i;
        a[1]=i/100;
        a[2]=(i%100)/10;
        a[3]=i%10;
        a[4]=b/100;
        a[5]=(b%100)/10;
        a[6]=b%10;
        a[7]=c/100;
        a[8]=(c%100)/10;
        a[9]=c%10;
        for (int j = 1; j <=9 ; ++j) {
            sum+=a[j];
        }
        if(sum==45){
            flag=sort();
            if(flag)
                printf("%d %d %d\n",i,b,c);
        }
    }

}