/*
2020 排序相减
题目来源： syu练习题
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
“排序相减”操作是指对于任意一个四位数n，将四个数字分别进行顺序排序和逆序排序，得到两个数取相减后结果的绝对值n1，
然后继续将n1中的四个数字进行顺序排序和逆序排序，得到两个数取相减后结果的绝对值n2,以此类推，最后总会得到一个数字黑洞，无法跳出。

例如:样例2中4176 = 6532 - 2356

Input
第一行输入一个整数T，表示数据组数（1<T<10000）；
第二行输入一个正整数n(1000<=n<=9999)和一个正整数k（1<=k<=100）,表示操作次数；
Output
对于每组数据，输出对于开始的数据n在第k次“排序相减”后结果绝对值。
Input示例
2
1234 2
3562 1
Output示例
8352
4176
 */
#include <stdio.h>

int get(int a[], int reverse) {
    int temp;
    if (!reverse) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3 - i; ++j) {
                if (a[j] > a[j + 1]) {
                    temp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3 - i; ++j) {
                if (a[j] < a[j + 1]) {
                    temp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int div(int n) {
    int a[4], i = 3, x, y;
    while (i >= 0) {
        a[i] = n % 10;
        n /= 10;
        i--;
    }
    x = get(a, 0);
    y = get(a, 1);
    return (x - y) > 0 ? x - y : y - x;
}

int main() {
    int T, n, k, nn;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &n, &k);
        while (k--) {
            nn = div(n);
            if (nn == n)
                break;
            n = nn;
        }
        printf("%d\n", n);
    }

    return 0;
}