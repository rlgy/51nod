//1265 四点共面
//
//给出三维空间上的四个点（点与点的位置均不相同），判断这4个点是否在同一个平面内（4点共线也算共面）。如果共面，输出"Yes"，否则输出"No"。
//Input
//第1行：一个数T，表示输入的测试数量(1 <= T <= 1000)
//第2 - 4T + 1行：每行4行表示一组数据，每行3个数，x, y, z, 表示该点的位置坐标(-1000 <= x, y, z <= 1000)。
//Output
//输出共T行，如果共面输出"Yes"，否则输出"No"。
//Input示例
//1
//1 2 0
//2 3 0
//4 0 0
//0 0 0
//Output示例
//        Yes
#include <stdio.h>

struct node {
    int x, y, z;
} a, b, c, d, e, f, g;

int fn(struct node v1, struct node v2, struct node v3) {
    int result;
    result = v1.x * v2.y * v3.z + v1.y * v2.z * v3.x + v1.z * v2.x * v3.y - v1.z * v2.y * v3.x - v1.y * v2.x * v3.z -
             v1.x * v2.z * v3.y;
    if (0 == result) {
        return 1;
    }
    return 0;
}

int main() {
    int t, r;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a.x, &a.y, &a.z);
        scanf("%d %d %d", &b.x, &b.y, &b.z);
        scanf("%d %d %d", &c.x, &c.y, &c.z);
        scanf("%d %d %d", &d.x, &d.y, &d.z);
        e.x = b.x - a.x;
        e.y = b.y - a.y;
        e.z = b.z - a.z;

        f.x = c.x - a.x;
        f.y = c.y - a.y;
        f.z = c.z - a.z;

        g.x = d.x - a.x;
        g.y = d.y - a.y;
        g.z = d.z - a.z;

        r = fn(e, f, g);

        if (r) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }

    }
    return 0;
}