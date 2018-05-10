/*
1067 Bash游戏 V2
基准时间限制：1 秒 空间限制：131072 KB 分值: 10 难度：2级算法题 收藏  关注
有一堆石子共有N个。A B两个人轮流拿，A先拿。每次只能拿1，3，4颗，拿到最后1颗石子的人获胜。假设A B都非常聪明，
拿石子的过程中不会出现失误。给出N，问最后谁能赢得比赛。
例如N = 2。A只能拿1颗，所以B可以拿到最后1颗石子。
Input
第1行：一个数T，表示后面用作输入测试的数的数量。（1 <= T <= 10000)
第2 - T + 1行：每行1个数N。(1 <= N <= 10^9)
Output
共T行，如果A获胜输出A，如果B获胜输出B。
Input示例
3
2
3
4
Output示例
B
A
A
*/
#include <stdio.h>
#include <string.h>

#define MAX 10007
#define MAXN 45

//A win: 1,3,4,5,6,8
//SG[x]=mem(S), mem(S)表示未在集合S中的最小非负整数
int SG[MAXN];//保存0-n的SG函数值
int S[MAXN];//x的后续状态的集合
int f[3] = {1, 3, 4}; //可改变的状态

void getSG() {
    for (int i = 1; i < MAXN; i++) {
        memset(S, 0, sizeof(S));//重置上一次的状态
        for (int j = 0; j < 3; j++) {
            if (i >= f[j])
                S[SG[i - f[j]]] = 1;
        }
        for (int j = 0;; j++) {
            if (!S[j]) {
                SG[i] = j;
                break;
            }
        }
    }
}

/**
 * SG函数打表找规律解决
 * @return
 */
int main() {
//    getSG();
//    for (int i = 0; i < MAXN; ++i) {
//        if (SG[i] == 0) {
//            printf("%d %d\n", i, SG[i]);
//        }
//    }
    int T, N[MAX];
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &N[i]);
    }
    //7的倍数或者MOD 7 =2 为P局面
    for (int i = 0; i < T; ++i) {
        if (N[i] % 7 == 0 || N[i] % 7 == 2)
            printf("B\n");
        else
            printf("A\n");
    }
    return 0;
}
