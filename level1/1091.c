/*
1091 线段的重叠
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
X轴上有N条线段，每条线段包括1个起点和终点。线段的重叠是这样来算的，[10 20]和[12 25]的重叠部分为[12 20]。
给出N条线段的起点和终点，从中选出2条线段，这两条线段的重叠部分是最长的。输出这个最长的距离。如果没有重叠，输出0。
Input
第1行：线段的数量N(2 <= N <= 50000)。
第2 - N + 1行：每行2个数，线段的起点和终点。(0 <= s , e <= 10^9)
Output
输出最长重复区间的长度。
Input示例
5
1 5
2 4
2 8
3 7
7 9
Output示例
4
 */

#include <stdio.h>

#define MAX 50001
struct Node {
    int s, e;
};

int mixed(struct Node a, struct Node b) {
    struct Node temp;
    if (a.s > a.e) {
        a.s ^= a.e;
        a.e ^= a.s;
        a.s ^= a.e;
    }
    if (b.s > b.e) {
        b.s ^= b.e;
        b.e ^= b.s;
        b.s ^= b.e;
    }
    if (a.s > b.s) {
        temp = a;
        a = b;
        b = temp;
    }
    if (a.e <= b.s) {
        return 0;
    } else if (a.e > b.s && a.e <= b.e) {
        return a.e - b.s;
    } else if (a.e > b.e) {
        return b.e - b.s;
    }
}

void fast_sort(struct Node l[], int left, int right) {
    struct Node key;
    int i, j;
    if (left > right)
        return;
    i = left;
    j = right;
    key = l[i];
    while (i < j) {
        while (i < j && key.s <= l[j].s)
            j--;
        l[i] = l[j];
        while (i < j && key.s >= l[i].s)
            i++;
        l[j] = l[i];
    }
    l[i] = key;
    fast_sort(l, left, i - 1);
    fast_sort(l, i + 1, right);
}

int main() {
    int N, i, max = 0, temp = 0, pos;
    scanf("%d", &N);

    struct Node l[MAX];
    for (i = 0; i < N; ++i) {
        scanf("%d %d", &l[i].s, &l[i].e);
        if (l[i].s > l[i].e) {
            l[i].s ^= l[i].e;
            l[i].e ^= l[i].s;
            l[i].s ^= l[i].e;
        }
    }
    fast_sort(l, 0, N - 1);

    pos = l[0].e;
    for (i = 1; i < N; i++) {
        if (l[i].e < pos) {
            temp = l[i].e - l[i].s;
        } else {
            temp = pos - l[i].s;
            pos = l[i].e;
        }
        if (max < temp)
            max = temp;
    }

    printf("%d", max);
    return 0;
}