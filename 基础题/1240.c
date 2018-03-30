//
// Created by rlgy on 18-3-30.
//

//1240 莫比乌斯函数
//莫比乌斯函数，由德国数学家和天文学家莫比乌斯提出。梅滕斯(Mertens)首先使用μ(n)（miu(n)）作为莫比乌斯函数的记号。（据说，高斯(Gauss)比莫比乌斯早三十年就曾考虑过这个函数）。
//具体定义如下：
//如果一个数包含平方因子，那么miu(n) = 0。例如：miu(4), miu(12), miu(18) = 0。
//如果一个数不包含平方因子，并且有k个不同的质因子，那么miu(n) = (-1)^k。例如：miu(2), miu(3), miu(30) = -1,miu(1), miu(6), miu(10) = 1。
//给出一个数n, 计算miu(n)。

#include<stdio.h>
#include<math.h>

int main() {
    int n;
    int x;
    int result;
    int flag;
    int sqr;

    result = -1;
    x = -1;
    flag = 0;

    scanf("%d", &n);

    sqr = (int) sqrt((double) n) + 1;

    for (int i = 2; i < sqr; i++) {
        while (n % i == 0) {
            n = n / i;
            flag++;
            result *= x;
        }
        if (flag > 1) {
            break;
        }
        flag = 0;
    }

    if (flag > 1) {
        printf("0");
    } else {
        printf("%d", result);
    }

    return 0;
}