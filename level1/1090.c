/*
1090 3个数和为0
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个长度为N的无序数组，数组中的元素为整数，有正有负包括0，并互不相等。从中找出所有和 = 0的3个数的组合。如果没有这样的组合，
 输出No Solution。如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则按照第二小的数排序。
Input
第1行，1个数N，N为数组的长度(0 <= N <= 1000)
第2 - N + 1行：A[i]（-10^9 <= A[i] <= 10^9)
Output
如果没有符合条件的组合，输出No Solution。
如果有多个，按照3个数中最小的数从小到大排序，如果最小的数相等则继续按照第二小的数排序。每行3个数，中间用空格分隔，并且这3个数按照从小到大的顺序排列。
Input示例
7
-3
-2
-1
0
1
2
3
Output示例
-3 0 3
-3 1 2
-2 -1 3
-2 0 2
-1 0 1
 */

#include <stdio.h>

#define MAX 1001

void fast_sort(int A[], int left, int right) {
    int key, i, j;
    if (left > right) {
        return;
    }
    key = A[left];
    i = left;
    j = right;
    while (i < j) {
        while (i < j && A[j] >= key) {
            j--;
        }
        A[i] = A[j];
        while (i < j && A[i] <= key) {
            i++;
        }
        A[j] = A[i];
    }
    A[i] = key;
    fast_sort(A, left, i - 1);
    fast_sort(A, i + 1, right);
}

int main() {
    int N, i, j, k, A[MAX] = {0}, f = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    fast_sort(A, 0, N - 1);

    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            for (k = j + 1; k < N; k++) {
                if (0 == A[i] + A[j] + A[k]) {
                    f = 1;
                    printf("%d %d %d\n", A[i], A[j], A[k]);
                    break;
                }
            }
        }
    }
    if (!f) {
        printf("No Solution\n");
    }
    return 0;
}