#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define max fmax


char s1[100], s2[100], s3[100];
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

bool compare(int s1[], int s2[], int la, int lb) {
	if (la != lb)
		return la > lb;
	for (int i = 1; i <= la; i++) {
		if (s1[i] != s2[i])
			return s1[i] > s2[i];
	}
	return true;
}			

int removezero(int c[], int lc) {
	for (int i = 1; i <= lc; i++)
		if (c[lc] == 0 && lc > 0)
			lc--;
	return lc;
}

void minus(int a[], int b[], int c[], int lc) {
    for (int i = 1; i <= lc; i++) {
        c[i] = a[i] - b[i];
        if (c[i] < 0) {
            c[i + 1]--;
            c[i] += 10;
        }
    }
}

int main() {
	scanf("%s %s", &s1, &s2);
	la = strlen(s1);
	lb = strlen(s2);
	if (!compare(s1, s2, la, lb)) {
		strcpy(s3, s1);
		strcpy(s1, s2);
		strcpy(s2, s3);
		printf("-");
	}
	trans(a, s1, la);
	trans(b, s2, lb);
	lc = max(la, lb);
	minus(a, b, c, lc);
	lc = removezero(c, lc);
	print(c, lc);

}


