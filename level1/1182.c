/*
1182 完美字符串
题目来源： Facebook Hacker Cup选拔
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
约翰认为字符串的完美度等于它里面所有字母的完美度之和。每个字母的完美度可以由你来分配，不同字母的完美度不同，分别对应一个1-26之间的整数。
约翰不在乎字母大小写。（也就是说字母F和f）的完美度相同。给定一个字符串，输出它的最大可能的完美度。例如：dad，你可以将26分配给d，25分配给a，这样整个字符串完美度为77。
Input
输入一个字符串S(S的长度 <= 10000)，S中没有除字母外的其他字符。
Output
由你将1-26分配给不同的字母，使得字符串S的完美度最大，输出这个完美度。
Input示例
dad
Output示例
77
 */

#include <stdio.h>
#include <string.h>

#define MAX 10001

void fast_sort(int A[], int left, int right) {
    int key, i, j;
    if (left > right) {
        return;
    }
    key = A[left];
    i = left;
    j = right;
    while (i < j) {
        while (i < j && A[j] >= key) {
            j--;
        }
        A[i] = A[j];
        while (i < j && A[i] <= key) {
            i++;
        }
        A[j] = A[i];
    }
    A[i] = key;
    fast_sort(A, left, i - 1);
    fast_sort(A, i + 1, right);
}

int main() {
    char S[MAX];
    int n[26] = {0}, len, l, result = 0;
    scanf("%s", S);
    len = strlen(S);
    for (int i = 0; i < len; i++) {
        if (S[i] >= 'a') {
            S[i] = 'A' + S[i] - 'a';
        }
        n[S[i] - 'A']++;
    }

    fast_sort(n, 0, 25);

    l = 26;

    while (l >= 1 && n[l - 1] > 0) {
        result += n[l-1] * l;
        l--;
    }
    printf("%d", result);
    return 0;
}