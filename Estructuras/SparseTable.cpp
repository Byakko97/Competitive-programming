//OR en rango

struct SparseTable{
	int t[N][LOGN], logt[N], n;
	void build(int _n){
		n = _n;
		For(i,0,n) t[i][0] = 1<<(s[i]-'a');
		for(int pw=1, lg=0; pw<=n; pw<<=1, lg++)
			For(i,pw,min(pw<<1,n+1))
				logt[i]=lg;
		For(k,1,LOGN)
			for(int i=0; i+(1<<k)<=n; i++)
				t[i][k] = t[i][k-1] | t[i+(1<<(k-1))][k-1];
	}
	int que(int l, int r){ //[l,r>
		r++;
		int lg = logt[r-l];
		int ans = t[l][lg] | t[r-(1<<lg)][lg];
		return __builtin_popcount(ans);
	}
} spt;
