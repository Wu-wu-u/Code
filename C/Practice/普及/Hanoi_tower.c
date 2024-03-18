#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void Hanoi(int n,char a,char b, char c){
    if(n==1) printf("%c-->%c\n",a,b);
    else{
        Hanoi(n-1,a,c,b);
        printf("%c-->%c\n",a,b);
        Hanoi(n-1,c,b,a);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char a='a',b='b',c='c';
    Hanoi(n,a,b,c);



    return 0;
}
/*古代某寺庙中有一个梵塔，塔内有3个座A、B和C，座A上放着64个大小不等的盘，其中大盘在下，小盘在上。
有一个和尚想把这64 个盘从座A搬到座B，但一次只能搬一个盘，搬动的盘只允许放在其他两个座上，
且大盘不能压在小盘上。现要求用程序模拟该过程，输入一个正整数n，代表盘子的个数，编写函数
*/
