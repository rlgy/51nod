/*
2130 进制转换
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
输入一个十进制整数n，和一个进制b，输出b进制下的n。
0 <= n <= 10^9
2 <= b <= 16

Input
一行两个整数n，b。
Output
一行一个字符串，表示进制转换后的结果。
特别注意对于超过10进制的11至16进制。
如果一位数字是10 11 12 13 14 15，我们用ABCDEF来代替。
Input示例
267242409 16
Output示例
FEDCBA9
 */
#include <stdio.h>

int main() {
    int n, b, len = 0;
    char ascii[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char result[30];
    scanf("%d %d", &n, &b);
    if (0 == n) {
        printf("0");
        return 0;
    }
    while (n) {
        result[len++] = ascii[n % b];
        n /= b;
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    return 0;
}