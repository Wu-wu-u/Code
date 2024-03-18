#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int cntB(char *s){
    int cnt=0;
    while(*s!='\0'){
        if(*s=='B') cnt++;
        s++;
    }
    return cnt;
}
int Aop(char *s,int NB){
    int l= strlen(s);
    char b[100][101];

    for (int i=0;i<l;i++){
        memset(b[i],0,sizeof (b[i]));
        for (int j=0;j<=i;j++){
            b[i][j]='A';
        }
        for(int k=i+1;k<l;k++){
            b[i][k]=s[k];
        }
        if(cntB(b[i])==NB) return i;
    }
}
int Bop(char *s,int NB){
    int l= strlen(s);
    char b[100][101];
    for (int i=0;i<l;i++){
        for (int j=0;j<=i;j++){
            b[i][j]='B';
        }
        for(int k=i+1;k<l;k++){
            b[i][k]=s[k];
        }
        if(cntB(b[i])==NB) return i;
    }
}
int main(){
    char s[100][101];
    int T,n;
    int NB;
    scanf("%d",&T);
    for (int i=0;i<T;i++){
        scanf("%d %d",&n,&NB);
        scanf("%s",s[i]);
        if(cntB(s[i])==NB) printf("0\n");
        else{
            Aop(s[i],NB)<Bop(s[i],NB)? printf("%d A\n", Aop(s[i],NB)+1) : printf("%d B\n", Bop(s[i],NB)+1);

        }
    }
    return 0;
}
/*给定一个长度为n仅含有字符A和字符B构成的字符串，再给定一个期望值k，你可以将字符串中包括第i个位置以及之前的所有字符都换成A或B，使得字符串中B的个数有k个。

你需要编写程序，求出可以达成期望的i，并给出用于替换的字符。

输入格式:
测试数据有T组(1≤T≤100)。
对于每组样例，第一行输入n(1≤n≤100)和k(1≤k≤n)。
第二行，输入长度为n仅含有字符A和字符B构成的字符串s。

输出格式:
若不需要进行替换，则输出一行0
若需要进行替换，输出一行，先输出开始替换的位置i，然后再输出用于替换的字符，之间用空格隔开。
如果i有多种可能，输出最小的一种即可。
输入样例:
在这里给出一组输入。例如：

3
6 2
AABBAA
5 3
AABAB
3 0
BAA
输出样例:
在这里给出相应的输出。例如：

0
1 B
1 A
样例解释
对于第一组样例，字符串s中已经有2个字符B了，故不需要进行替换操作，输出0。
对于第二组样例，唯一的方法就是把第一个位置的字符替换为B，这样新的字符串中才能有3个B，即AABAB→ 
BABAB，故输出1 B。
对于第三组样例，替换方案中最小的i是1，即BAA→ 
AAA，故输出1 A。*/
