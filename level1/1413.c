//
// Created by rlgyzhcn on 2019/11/3 20:34.
//

//1413 权势二进制
//
//一个十进制整数被叫做权势二进制，当他的十进制表示的时候只由0或1组成。例如0，1，101，110011都是权势二进制而2，12，900不是。
//
//当给定一个n的时候，计算一下最少要多少个权势二进制相加才能得到n。
//
//输入
//单组测试数据。
//第一行给出一个整数n (1<=n<=1,000,000)
//输出
//输出答案占一行。
//输入样例
//9
//输出样例
//9


#include <stdio.h>

#define APP_ENV_TEST

int getValue(int n, int x, int y);

int main() {
    FILE *input;
    int N;
    int c = 0;
    int x, y;

#ifdef APP_ENV_TEST
    // 打开文件读取数据
    input = fopen("/mnt/hgfs/code/c/first/input.txt", "r");
    if (input == NULL) {
        return 0;
    }
#else
    input = stdin;
#endif

    fscanf(input, "%d", &N);


    while (N) {
        x = N;
        y = 1;
        while (x >= 10) {
            x /= 10;
            y++;
        }
        c += x;
        N = getValue(N, x, y);
    }
    printf("%d", c);
    return 0;
}

int getValue(int n, int x, int y) {
    int a = 0, b = 0;
    int pos = 1;

    for (int i = 0; i < y; ++i) {
        a = i;
        pos = 1;
        while (a) {
            pos *= 10;
            a--;
        }
        b = (n / pos) % 10;
        if (b > x) {
            n -= x * pos;
        } else {
            n -= b * pos;
        }
    }
    return n;
}