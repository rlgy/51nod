//
// Created by rlgyzhcn on 2019/10/27 18:23.
//

//贪心算法 Codility 单调栈

//有一口井，井的高度为N，每隔1个单位它的宽度有变化。现在从井口往下面扔圆盘，如果圆盘的宽度大于井在某个高度的宽度，则圆盘被卡住（恰好等于的话会下去）。
//盘子有几种命运：1、掉到井底。2、被卡住。3、落到别的盘子上方。
//盘子的高度也是单位高度。给定井的宽度和每个盘子的宽度，求最终落到井内的盘子数量。
//如图井和盘子信息如下：
//井：5 6 4 3 6 2 3
//盘子：2 3 5 2 4
//最终有4个盘子落在井内。

//输入
//第1行：2个数N, M中间用空格分隔，N为井的深度，M为盘子的数量(1 <= N, M <= 50000)。
//第2 - N + 1行，每行1个数，对应井的宽度Wi(1 <= Wi <= 10^9)。
//第N + 2 - N + M + 1行，每行1个数，对应盘子的宽度Di(1 <= Di <= 10^9)
//输出
//输出最终落到井内的盘子数量。
//输入样例
//7 5
//5
//6
//4
//3
//6
//2
//3
//2
//3
//5
//2
//4
//输出样例
//4

#include <stdio.h>
#include <string.h>


#define APP_ENV_TEST

#define MAX_LENGTH 50000

int main() {
    FILE *input;
    int N = 0, M = 0;
    int C = 0; // 落入井中的盘子个数
    int L = 0; // 当前井的深度
    int W[MAX_LENGTH] = {0}; // 井的宽度
    int H[MAX_LENGTH] = {0}; // 每层的深度
    int D = 0; // 当前盘子的宽度
    int t = 0;

#ifdef APP_ENV_TEST
    // 打开文件读取数据
    input = fopen("/mnt/hgfs/code/c/first/input.txt", "r");
    if (input == NULL) {
        return 0;
    }
#else
    input = stdin;
#endif

    fscanf(input, "%d %d", &N, &M);

    H[0] = 1;
    fscanf(input, "%d", &W[0]);

    for (int i = 1; i < N; ++i) {
        fscanf(input, "%d", &t);
        if (t < W[L]) {
            L++;
            W[L] = t;
            H[L] = 1;
        } else {
            H[L]++;
        }
    }

    while (L >= 0) {
        fscanf(input, "%d", &D);

        while (L >= 0 && (D > W[L] || H[L] <= 0)) {
            L--;
        }
        if (L < 0) {
            break;
        }
        H[L]--;
        C++;
        if (H[L] <= 0) {
            L--;
        }
    }

    printf("%d\n", C);
    return 0;
}

