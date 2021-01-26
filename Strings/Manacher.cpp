int best[2][N]; //best[0][i] = mayor palindromo que acaba en i, best[1][i] mayor palindromo que comienza en i
int n;
string s;
int d1[N], d2[N];

void manacher(){
	For(i,0,n)
		best[0][i]=best[1][i]=1;
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			best[1][i-k]=max(best[1][i-k],k<<1|1);
			best[0][i+k]=max(best[0][i+k],k<<1|1);
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			best[1][i-k-1]=max(best[1][i-k-1],k*2+2);
			best[0][i+k]=max(best[0][i+k],k*2+2);
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
}
