//
// Created by rlgy on 18-3-30.
//

//1264 线段相交
//给出平面上两条线段的两个端点，判断这两条线段是否相交（有一个公共点或有部分重合认为相交）。 如果相交，输出"Yes"，否则输出"No"。
//Input
//第1行：一个数T，表示输入的测试数量(1 <= T <= 1000)
//第2 - T + 1行：每行8个数，x1,y1,x2,y2,x3,y3,x4,y4。(-10^8 <= xi, yi <= 10^8)
//(直线1的两个端点为x1,y1 | x2, y2,直线2的两个端点为x3,y3 | x4, y4)
//Output
//输出共T行，如果相交输出"Yes"，否则输出"No"。
//Input示例
//2
//1 2 2 1 0 0 2 2
//-1 1 1 1 0 0 1 -1
//Output示例
//Yes
//No

#include <stdio.h>

struct node {
    float x;
    float y;
} a, b, c, d;

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int across(struct node a, struct node b, struct node p) {
    double result;
    result = (p.x - a.x) * (b.y - a.y) - (b.x - a.x) * (p.y - a.y);
    if (0 == result) {
        return 0;
    } else if (result > 0) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    int loop, t1, t2, t3, t4;
    scanf("%d", &loop);

    while (loop) {
        scanf("%f %f %f %f %f %f %f %f", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
        if (min(a.x, b.x) <= max(c.x, d.x) && max(a.x, b.x) >= min(c.x, d.x) && min(a.y, b.y) <= max(c.y, d.y) &&
            max(a.y, b.y) >= min(c.y, d.y)) {
            t1 = across(a, b, c);
            t2 = across(a, b, d);
            t3 = across(c, d, a);
            t4 = across(c, d, b);
            if (t1 * t2 <= 0 && t3 * t4 <= 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        } else {
            printf("No\n");
        }
        --loop;
    }

    return 0;
}