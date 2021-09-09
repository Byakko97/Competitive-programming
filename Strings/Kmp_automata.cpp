struct kmpAutomata {
	int pi[N], kmp[N][ALPH];	
	string s;

	int go(int i, int j){
		if(kmp[i][j] != -1) return kmp[i][j];
		int ans;
		if(s[i] == j + 'a') ans = i + 1;
		else if(i == 0) ans = 0;
		else ans = go(pi[i-1], j);
		return kmp[i][j] = ans;
	}

	kmpAutomata(string _s) s(_s) {
		int n = sz(s);
		int k = 0;
		For(i, 1, n){
			while(k > 0 && s[i] != s[k]) k = pi[k-1];
			if(s[i] == s[k]) k++;
			pi[i] = k;
		}
		For(i,0,n) For(j,0,ALPH) kmp[i][j] = -1;
		For(i,0,n) For(j,0,ALPH)
			go(i, j);
	}
};
