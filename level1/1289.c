/*
1289 大鱼吃小鱼
题目来源： Codility
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
有N条鱼每条鱼的位置及大小均不同，他们沿着X轴游动，有的向左，有的向右。游动的速度是一样的，两条鱼相遇大鱼会吃掉小鱼。
从左到右给出每条鱼的大小和游动的方向（0表示向左，1表示向右）。问足够长的时间之后，能剩下多少条鱼？
Input
第1行：1个数N，表示鱼的数量(1 <= N <= 100000)。
第2 - N + 1行：每行两个数A[i], B[i]，中间用空格分隔，分别表示鱼的大小及游动的方向
(1 <= A[i] <= 10^9，B[i] = 0 或 1，0表示向左，1表示向右）。
Output
输出1个数，表示最终剩下的鱼的数量。
Input示例
5
4 0
3 1
2 0
1 0
5 0
Output示例
2
 */
#include <stdio.h>

#define MAX 100001

int main() {
    //使用栈
    int N, S[MAX], cnt = 0, v = 0, d = 0, len = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &v, &d);
        if (!d) {
            if (len == 0) {
                cnt++;
            } else {
                //eat
                for (int i = len - 1; i >= 0; --i) {
                    if (S[i] < v) {
                        len--;
                        if (len == 0) {
                            cnt++;
                        }
                    } else
                        break;
                }
            }
        } else {
            S[len++] = v;
        }
    }
    printf("%d", cnt + len);
    return 0;
}