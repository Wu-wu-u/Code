#include <stdio.h>
long long route_number[40][40]; //非常重要之 lognlong 最后可能路线很多
int horse_control[40][40];
struct point{
    int x;
    int y;
};
struct point horse;
struct point b;

void horse_cl(){ //有马的位置
    horse_control[horse.x+1][horse.y+2]=1;
    horse_control[horse.x+1][horse.y-2]=1;
    horse_control[horse.x-1][horse.y+2]=1;
    horse_control[horse.x-1][horse.y-2]=1;
    horse_control[horse.x+2][horse.y+1]=1;
    horse_control[horse.x+2][horse.y-1]=1;
    horse_control[horse.x-2][horse.y+1]=1;
    horse_control[horse.x-2][horse.y-1]=1;
    horse_control[horse.x][horse.y]=1;
    return;
}


int main(){
    scanf("%d %d %d %d",&b.x,&b.y,&horse.x,&horse.y);
    horse.x+=2; //2防止马数组越界
    horse.y+=2;
    b.x+=2;
    b.y+=2;
    route_number[1][2]=1; //拟定一个假值 保证动态规划正常进行
    horse_cl();
    for (int i=2;i<=b.x;i++) {
        for (int j = 2; j <= b.y; j++) {
            if(horse_control[i][j]!=1)
                route_number[i][j]=route_number[i-1][j]+route_number[i][j-1];

        }
    }
    printf("%lld",route_number[b.x][b.y]);
}
//