// Remember that pi[i] is the length of the longest (proper) prefix of s[0, i]
// that is also a (proper) suffix of s[0, i]
int pi[N];

void kmp(string& s) {
	int n = sz(s);
	int k = 0;
	For(i, 1, n){
		while(k > 0 && s[i] != s[k]) k = pi[k-1];
		if(s[i] == s[k]) k++;
		pi[i] = k;
	}
}
