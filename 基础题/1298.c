//1298 圆与三角形
//
//给出圆的圆心和半径，以及三角形的三个顶点，问圆同三角形是否相交。相交输出"Yes"，否则输出"No"。（三角形的面积大于0）。
//Input
//        第1行：一个数T，表示输入的测试数量(1 <= T <= 10000)，之后每4行用来描述一组测试数据。
//4-1：三个数，前两个数为圆心的坐标xc, yc，第3个数为圆的半径R。(-3000 <= xc, yc <= 3000, 1 <= R <= 3000）
//4-2：2个数，三角形第1个点的坐标。
//4-3：2个数，三角形第2个点的坐标。
//4-4：2个数，三角形第3个点的坐标。(-3000 <= xi, yi <= 3000）
//Output
//        共T行，对于每组输入数据，相交输出"Yes"，否则输出"No"。
//Input示例
//2
//0 0 10
//10 0
//15 0
//15 5
//0 0 10
//0 0
//5 0
//5 5
//Output示例
//        Yes
//No
#include <stdio.h>
#include <math.h>

struct cycle {
    double x, y, r;
} o;

struct node {
    double x, y;
} a, b, c;

double olen(struct cycle x, struct node y) {
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
}

double llen(struct node x, struct node y) {
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
}

double dlen(struct cycle x0,struct node x1,struct node x2){
    double result,k;
    if(x1.y==x2.y){
        return fabs(x1.y-x0.y);
    }
    k=(x1.x-x2.x)/(x1.y-x2.y);
    result=(x0.x-k*x0.y+x2.y*k-x2.x)/sqrt(1+k*k);
    return fabs(result);
}

int is_acute(double a, double b, double c) {
    double acute = (a * a + b * b - c * c) / (2 * a * b);
    if (acute < 1 && acute > 0)
        return 1;
    return 0;
}

int main() {

    int t;
    double oa, ob, oc, ab, ac, bc;
    scanf("%d", &t);
    while (t--) {
        scanf("%lf %lf %lf", &o.x, &o.y, &o.r);
        scanf("%lf %lf", &a.x, &a.y);
        scanf("%lf %lf", &b.x, &b.y);
        scanf("%lf %lf", &c.x, &c.y);

        oa = olen(o, a);
        ob = olen(o, b);
        oc = olen(o, c);
        if (oa < o.r && ob < o.r && oc < o.r) {
            printf("No\n");
        } else if (oa > o.r && ob > o.r && oc > o.r) {
            if(dlen(o,a,b)<=o.r){
                ab = llen(a, b);
                if (is_acute(ab, oa, ob) && is_acute(ab, ob, oa)) {
                    printf("Yes\n");
                    continue;
                }
            }

            if(dlen(o,a,c)<=o.r){
                ac = llen(a, c);
                if (is_acute(ac, oa, oc) && is_acute(ac, oc, oa)) {
                    printf("Yes\n");
                    continue;
                }
            }

            if(dlen(o,b,c)<=o.r){
                bc = llen(c, b);
                if (is_acute(bc, ob, oc) && is_acute(bc, oc, ob)) {
                    printf("Yes\n");
                    continue;
                }
            }
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }

    return 0;
}
