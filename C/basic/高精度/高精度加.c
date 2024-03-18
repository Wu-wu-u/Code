#include <stdio.h>
#include <math.h>
#include <string.h>
#define max fmax
int a[505], b[505], c[505], la, lb, lc;
char s1[505], s2[505];

void trans(int a[], char s[], int la) {
	for (int i = 0; i < la; i++) {
		a[la - i] = s[i] - '0';
	}
}


int main() {

	scanf("%s", &s1);
	scanf("%s", &s2);

	la = strlen(s1);
	lb = strlen(s2);
	trans(a, s1, la);
	trans(b, s2, lb);
	lc = max(la, lb) + 1;
	for (int i = 1; i <= lc; i++) {
		c[i] = c[i] + a[i] + b[i];
		c[i + 1] = c[i] / 10;
		c[i] = c[i] % 10;
	}
	if (c[lc] == 0 && lc > 0)
		lc = lc - 1;
	for (int j = lc; j >= 1; j--)
		printf("%d", c[j]);

}
