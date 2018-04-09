/*
1001 数组中和等于K的数对
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个整数K和一个无序数组A，A的元素为N个互不相同的整数，找出数组A中所有和等于K的数对。例如K = 8，数组A：{-1,6,5,3,4,2,9,0,8}，
 所有和等于8的数对包括(-1,9)，(0,8)，(2,6)，(3,5)。
Input
第1行：用空格隔开的2个数，K N，N为A数组的长度。(2 <= N <= 50000，-10^9 <= K <= 10^9)
第2 - N + 1行：A数组的N个元素。（-10^9 <= A[i] <= 10^9)
Output
第1 - M行：每行2个数，要求较小的数在前面，并且这M个数对按照较小的数升序排列。
如果不存在任何一组解则输出：No Solution。
Input示例
8 9
-1
6
5
3
4
2
9
0
8
Output示例
-1 9
0 8
2 6
3 5
 */

#include <stdio.h>

#define MAX 50000

void fast_sort(int *a, int left, int right) {
    int i, j, key;
    if (left >= right) {
        return;
    }
    i = left;
    j = right;
    key = a[left];
    while (i < j) {
        while (i < j && key <= a[j]) {
            j--;
        }
        a[i] = a[j];
        while (i < j && key >= a[i]) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    fast_sort(a, left, i - 1);
    fast_sort(a, i + 1, right);
}

int main() {
    int N, K, a[MAX], i = 0, j, temp, flag = 1;
    scanf("%d %d", &K, &N);
    while (i < N) {
        scanf("%d", &a[i++]);
    }

    fast_sort(a, 0, N - 1);

    i = 0;
    j = N - 1;
    while (i < j) {
        if (K == a[i] + a[j]) {
            flag = 0;
            printf("%d %d\n", a[i], a[j]);
            i++;
            j--;
        } else if (K <= a[i] + a[j]) {
            j--;
        } else {
            i++;
        }
    }
    if (flag)
        printf("No Solution");
    return 0;
}