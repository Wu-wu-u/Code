#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int map[100][100];
int book[100][100];
int n,sx,sy,ex,ey,flag;
int dr[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int stp[1000];
int cnt;
void dfs(int x,int y,int step){
    int nx,ny;
    if(x==ex&&y==ey){
        flag=1;
        stp[cnt++]=step;
        return;
    }
    for (int i=0;i<4;i++){
        nx=x+dr[i][0];
        ny=y+dr[i][1];
        if(nx<0||nx>n-1||ny<0||ny>n-1){
            continue;
        }
        if(map[nx][ny]==0&&book[nx][ny]==0){
            book[nx][ny]=1;
            dfs(nx,ny,step+1);
            book[nx][ny]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    ex=n-2;ey=n-2;
    dfs(1,1,0);
    int min=0;
    for(int i=0;i<cnt;i++){
        if(stp[i]<=stp[min]) min=i;
    }
    if(flag)printf("%d",stp[min]);
    else printf("No solution");
    
    return 0;
}
/*递归求解迷宫最短通道的总步长。输入一个迷宫，求从入口通向出口的可行路径中最短的路径长度。为简化问题，迷宫用二维数组
int maze[10][10]来存储障碍物的分布，假设迷宫的横向和纵向尺寸的大小是一样的，并由程序运行读入, 若读入迷宫大小的值是n（3<n<=10），则该迷宫横向或纵向尺寸都是n，规定迷宫最外面的一圈是障碍物，迷宫的入口是maze[1][1]，出口是maze[n-2][n-2], 若maze[i][j] = 1代表该位置是障碍物，若maze[i][j] = 0代表该位置是可以行走的空位（0<=i<=n-1, 0<=j<=n-1）。求从入口maze[1][1]到出口maze[n-2][n-2]可以走通的路径上经历的最短的总步长。要求迷宫中只允许在水平或上下四个方向的空位上行走，走过的位置不能重复走。

输入格式:
输入迷宫大小的整数n, 以及n行和n列的二维数组（数组元素1代表障碍物，0代表空位）

输出格式:
若有可行的通道则输出一个整数，代表求出的通道的最短步长；若没有通道则输出"No solution" */
