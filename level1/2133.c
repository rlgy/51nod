/*
2133 排队接水
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题
n个人一起排队接水，第i个人需要a[i]的时间来接水。
1 <= n <= 1000
1 <= a[i] <= 1000
同时只能有一个人接水，正在接水的人和没有接水的人都需要等待。
完成接水的人会立刻消失，不会继续等待。
你可以决定所有人接水的顺序，并希望最小化所有人等待时间的总和。
Input
第一行一个整数n
接下来n行，每行一个整数表示a[i]
Output
一行一个整数，表示所有人等待时间的总和的最小值
Input示例
3
1
2
3
Output示例
10=1+3+6
*/
//#include <stdio.h>
//
//#define MAX 1007
//
//void fast_sort(int a[], int left, int right) {
//    int i, j, key;
//    if (left > right)
//        return;
//    i = left;
//    j = right;
//    key = a[i];
//    while (i < j) {
//        while (i < j && a[j] >= key)
//            j--;
//        a[i] = a[j];
//        while (i < j && a[i] <= key)
//            i++;
//        a[j] = a[i];
//    }
//    a[i] = key;
//    fast_sort(a, left, i - 1);
//    fast_sort(a, i + 1, right);
//}
//
//int main() {
//    int n, a[MAX], result = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &a[i]);
//    }
//    fast_sort(a, 0, n - 1);
//    for (int i = 0; i < n; ++i) {
//        result += a[i] * (n - i);
//    }
//    printf("%d", result);
//    return 0;
//}

//桶排序
#include <stdio.h>

#define MAX 1007


int main() {
    int n, index, a[MAX] = {0}, result = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &index);
        a[index]++;
    }
    for (int i = 1; i < MAX; ++i) {
        while (a[i]) {
            result += (n--) * i;
            a[i]--;
        }
    }
    printf("%d", result);
    return 0;
}