#include <stdio.h>
#include<stdlib.h>
#include <limits.h>
#include <string.h>

int m[101][101];
int s[101][101];

void optimal_matrix_chain(int p[], int n) {
    int i, r, j, k, t;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (r = 2; r <= n; r++) {
        for (i = 1; i <= n - r + 1; i++) {
            j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (k = i + 1; k <= j - 1; k++) {
                t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_order(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    }
    else {
        printf("(");
        print_order(i, s[i][j]);
        print_order(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int p[100];
    int i, j, k, n, a;

    printf("�������м�������");
    scanf("%d", &n);
    printf("����������P��ȷ��ÿ�������С��\n");
    for (a = 0; a <= n; a++) {
        scanf("%d", &p[a]);
    }
    optimal_matrix_chain(p, n);
    printf("\n������С����Ϊ��%d\n", m[1][n]);
    printf("���ų˷�����Ϊ��");
    print_order(1, n);
    return 0;
}