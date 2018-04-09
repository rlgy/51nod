#include <stdio.h>
#include <math.h>

int s[10] = {0}, len;

void printS() {
    for (int i = 0; i < len; ++i) {
        printf("%d", s[i]);
    }
    printf("\n");
}

void swap(int a, int b) {
    int temp;
    temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

int main() {
    char c;
    int i, j;
    while ((c = getchar()) != '\n') {
        s[len++] = c - '0';
    }

    for (i = 0; i < len; ++i) {
        for (j = 0; j < len - i - 1; ++j) {
            if (s[j] > s[j + 1]) {
                swap(j, j + 1);
            }
        }
    }

    while (1) {
        printS();
        for (i = len - 2; i >= 0 && s[i] >= s[i + 1]; --i) {

        }
        if (i < 0)
            break;
        for (j = len - 1; i < j && s[j] <= s[i]; --j) {

        }
        swap(i, j);
        i++;
        j = len - 1;
        while (i < j) {
            swap(i++, j--);
        }
    }
    return 0;
}