#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define max fmax

char s1[100], s2[100];
int a[100], b[100], c[100], la, lb, lc;

void trans(int a[], char s[], int la) {
	for (int i = 0; i < la; i++) {
		a[la - i] = s[i] - '0';
	}
}


void print(int c[], int lc) {
	for (int i = lc; i >= 1; i--)
		printf("%d", c[i]);
}


int removezero(int c[], int lc) {
	for (int i = 1; i <= lc; i++)
		if (c[lc] == 0 && lc > 0)
			lc--;
	return lc;
}

void multiply(int a[], int b[], int c[], int la, int lb, int lc) {
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			c[i + j - 1] += a[i] * b[j];
			c[i + j] += c[i + j - 1] / 10;
			c[i + j - 1] %= 10;
		}
	}
}

int main() {
	scanf("%s %s", &s1, &s2);
	la = strlen(s1);
	lb = strlen(s2);
	trans(a, s1, la);
	trans(b, s2, lb);
	lc = la + lb;
	multiply(a, b, c, la, lb, lc);
	lc = removezero(c, lc);
	print(c, lc);

}


