//
// Created by rlgyz on 2019/10/20.
//

/**
 * 一个单词a如果通过交换单词中字母的顺序可以得到另外的单词b，那么定义b是a的Anigram，
 * 例如单词army和mary互为Anigram。另：相同的2个单词不算Anigram。现在给定一个字典，
 * 输入Q个单词，从给出的字典中找出这些单词的Anigram。
 * 输入
 * 第1行：1个数N，表示字典中单词的数量。(1 <= N <= 10000)
 * 第2 - N + 1行，字典中的单词，单词长度 <= 10。
 * 第N + 2行：查询的数量Q。(1 <= Q <= 10000)
 * 第N + 3 - N + Q - 2行：用作查询的单词，单词长度 <= 10。
 * 输出
 * 共Q行，输出Anigram的数量，如果没有输出0。
 * 输入样例
 * 5
 * add
 * dad
 * bad
 * cad
 * did
 * 3
 * add
 * cac
 * dda
 * 输出样例
 * 1
 * 0
 * 2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIC_LENGTH 10000
#define MAX_DIC_NUMBER_LENGTH 10

void move(char *s, int i, int j) {
    char c;
    c = s[i];
    while (i > j) {
        s[i] = s[i - 1];
        i--;
    }
    s[j] = c;
}

void natural_sort_string(char *s) {
    int i = 0, j = 0;
    int strLen = (int) strlen(s);
    for (i = 1; i < strLen; i++) {
        for (j = 0; j < i; j++) {
            if (s[i] < s[j]) {
                move(s, i, j);
            }
        }
    }
}

void move_str(char *a[], char *p, int i, int l) {
    a[l] = (char *) malloc(sizeof(char) * MAX_DIC_NUMBER_LENGTH);
    while (l > i) {
        strcpy(a[l], a[l - 1]);
        l--;
    }
    strcpy(a[i], p);
}

void move_count(int *a, int i, int l) {
    while (l > i) {
        a[l] = a[l - 1];
        l--;
    }
    a[i] = 1;
}

// 字典序存储字符串
void sort_save_hash(char *a[], int *c, char *p, int *len, int i, int j) {
    int m = 0;
    if (strcmp(a[i], p) > 0) {
        move_str(a, p, i, *len);
        move_count(c, i, *len);
        (*len) += 1;
        return;
    }
    if (strcmp(a[j], p) < 0) {
        move_str(a, p, j + 1, *len);
        move_count(c, j + 1, *len);
        (*len)++;
        return;
    }
    m = (i + j) / 2;
    if (strcmp(a[m], p) > 0) {
        sort_save_hash(a, c, p, len, i, m - 1);
    } else if (strcmp(a[m], p) < 0) {
        sort_save_hash(a, c, p, len, m + 1, j);
    } else {
        c[m] += 1;
        return;
    }
}

void sort_save_dic(char *a[], char *p, int i, int j, int len) {
    int m = 0;
    if (strcmp(a[i], p) >= 0) {
        move_str(a, p, i, len);
        return;
    }
    if (strcmp(a[j], p) <= 0) {
        move_str(a, p, j + 1, len);
        return;
    }
    m = (i + j) / 2;
    if (strcmp(a[m], p) > 0) {
        sort_save_dic(a, p, i, m - 1, len);
    } else if (strcmp(a[m], p) < 0) {
        sort_save_dic(a, p, m + 1, j, len);
    } else {
        move_str(a, p, m, len);
        return;
    }
}

int find(char *a[], char *p, int len, int *idx) {
    int i = 0, j = 0, m = 0;
    j = len - 1;
    if (strcmp(a[i], p) > 0) {
        return 0;
    }
    if (strcmp(a[j], p) < 0) {
        return 0;
    }
    while (i <= j) {
        m = (i + j) / 2;
        if (strcmp(a[m], p) == 0) {
            (*idx) = m;
            return 1;
        } else if (strcmp(a[m], p) > 0) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return 0;
}


int main() {
    int dicLen = 0, queLen = 0, hashLen = 0;
    int i = 0, c = 0, r = 0, f = 0;
    int hashCount[MAX_DIC_LENGTH] = {0};
    char *dicNumber[MAX_DIC_LENGTH];
    char *hashNumber[MAX_DIC_LENGTH];
    char tmp[10] = "";

    scanf("%d", &dicLen);

    for (i = 0; i < dicLen; i++) {
        scanf("%s", tmp);
        if (i == 0) {
            dicNumber[0] = (char *) malloc(sizeof(char) * MAX_DIC_NUMBER_LENGTH);
            strcpy(dicNumber[0], tmp);
            natural_sort_string(tmp);
            hashNumber[0] = (char *) malloc(sizeof(char) * MAX_DIC_NUMBER_LENGTH);
            strcpy(hashNumber[0], tmp);
            hashCount[0] = 1;
            hashLen = 1;
            continue;
        }
        // 存储原始值
        sort_save_dic(dicNumber, tmp, 0, i - 1, i);
        natural_sort_string(tmp);
        sort_save_hash(hashNumber, hashCount, tmp, &hashLen, 0, hashLen - 1);
    }
    scanf("%d", &queLen);

    for (i = 0; i < queLen; i++) {
        scanf("%s", tmp);
        c = find(dicNumber, tmp, dicLen, &r);
        natural_sort_string(tmp);
        f = find(hashNumber, tmp, hashLen, &r);
        if (!f) {
            printf("0\n");
            continue;
        }
        printf("%d\n", hashCount[r] - c);
    }
    return 0;
}