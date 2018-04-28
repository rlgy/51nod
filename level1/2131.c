/*
2131 二维数组转置
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
输入一个n行m列的数组，输出他的转置，具体来说
输出的第i行第j个数字，应是输入的第j行第i个数字。
1 <= n <= 20000
1 <= m <= 20000
1 <= n * m <= 20000
1 <= a[i][j] <= 1000
特别注意，你并不能声明一个二维数组，两维的大小都是20000。（回顾课件中，数组不能太大，二维数组的大小是两维的乘积）
如果你不会做本题，请特别复习课件中，如何用一维数组模拟二维数组。（二维数组本质上和一维数组等价，所以你只需要一个大小为20000一维数组）
Input
第一行两个整数n, m表示数组的行数和列数
接下来n行，每行m个整数表示数组内容。
Output
第一行先输出m, n。
接下来输出转置的结果，共m行n列。
其中第i行第j个数字，应是输入的第j行第i个数字。
Input示例
3 2
1 2
3 4
5 6
Output示例
2 3
1 3 5
2 4 6
 */
#include <stdio.h>

#define MAX 20001

int main() {
    int n, m, a[MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i * m + j]);
        }
    }
    printf("%d %d\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            printf("%d ", a[i + j * m]);
        }
        printf("%d\n", a[(n - 1) * m + i]);
    }
    return 0;
}