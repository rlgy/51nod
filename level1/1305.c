/*
1305 Pairwise Sum and Divide
题目来源： HackerRank
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
有这样一段程序，fun会对整数数组A进行求值，其中Floor表示向下取整：

fun(A)
    sum = 0
    for i = 1 to A.length
        for j = i+1 to A.length
            sum = sum + Floor((A[i]+A[j])/(A[i]*A[j]))
    return sum

给出数组A，由你来计算fun(A)的结果。例如：A = {1, 4, 1}，fun(A) = [5/4] + [2/1] + [5/4] = 1 + 2 + 1 = 4。
Input
第1行：1个数N，表示数组A的长度(1 <= N <= 100000)。
第2 - N + 1行：每行1个数A[i]（1 <= A[i] <= 10^9)。
Output
输出fun(A)的计算结果。
Input示例
3
1 4 1
Output示例
4
 */
#include <stdio.h>

#define MAX 100001

int main() {
    //使用栈
    int N, A[MAX], x = 0, y = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1)
            x++;
        else if (A[i] == 2)
            y++;
    }
    printf("%d", x * (x - 1) + x * (N - x) + y * (y - 1) / 2);
    return 0;
}