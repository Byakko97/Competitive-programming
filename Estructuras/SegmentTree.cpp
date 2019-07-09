struct SegmentTree{
	int n;
	int t[N<<1];
	void build(){
		rip(i,n-1,1){
			t[i]=f(t[i<<1], t[i<<1 | 1]);
		}
	}
	void update(int i, int v){
		for(t[i+=n]=v; i>1; i>>=1){
			int aux=t[i>>1];
			t[i>>1]=f(t[i], t[i^1]);
			if(aux==t[i>>1]) break;
		}
	}
	int que(int l, int r){
		int ans=neutro;
		for(l+=n, r+=n;l<r; l>>=1, r>>=1){
			if(l & 1) ans=f(ans, t[l++]);
			if(r & 1) ans=f(ans, t[--r]);
		}
		return ans;
	}
} st;
