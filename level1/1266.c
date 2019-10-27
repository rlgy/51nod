//
// Created by rlgyzhcn on 2019/10/27 17:29.
//


//n只蚂蚁以每秒1cm的速度在长为Lcm的竿子上爬行。当蚂蚁爬到竿子的端点时就会掉落。
// 由于竿子太细，两只蚂蚁相遇时，它们不能交错通过，只能各自反向爬回去。对于每只
// 蚂蚁，我们知道它距离竿子左端的距离xi，但不知道它当前的朝向。请计算各种情况
// 当中，所有蚂蚁落下竿子所需的最短时间和最长时间。

//输入
//第1行：2个整数N和L，N为蚂蚁的数量，L为杆子的长度(1 <= L <= 10^9, 1 <= N <= 50000)
//第2 - N + 1行：每行一个整数A[i]，表示蚂蚁的位置(0 < A[i] < L)
//输出
//输出2个数，中间用空格分隔，分别表示最短时间和最长时间。
//输入样例
//3 10
//2
//6
//7
//输出样例
//4 8

#include <stdio.h>
#include <string.h>

#define APP_ENV_TEST

int getMax(int length, int position);

int getMin(int length, int position);

int main() {
    FILE *input;
    int N = 0, L = 0, max = 0, min = 0, tmp = 0, pos = 0;

#ifdef APP_ENV_TEST
    // 打开文件读取数据
    input = fopen("/mnt/hgfs/code/c/first/input.txt", "r");
    if (input == NULL) {
        return 0;
    }
#else
    input = stdin;
#endif
    fscanf(input, "%d %d", &N, &L);
    while (N > 0) {
        fscanf(input, "%d", &pos);
        tmp = getMax(L, pos);
        max = max > tmp ? max : tmp;
        tmp = getMin(L, pos);
        min = min > tmp ? min : tmp;
        N--;
    }
    printf("%d %d\n", min, max);
    return 0;
}

int getMax(int length, int position) {
    int l = 0, r = 0;
    l = position;
    r = length - position;
    return l > r ? l : r;
}

int getMin(int length, int position) {
    int l = 0, r = 0;
    l = position;
    r = length - position;
    return l < r ? l : r;
}