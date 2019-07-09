struct SegmentTree{
	int N;
	int A[2 * MAX_N];
	void build(){
		for(int i=n-1; i>0; i--){
			A[i]=f(A[i<<1], A[i<<1 | 1]);
		}
	}
	void update(int i, int v){
		for(A[i+=N]=v; i>1; i>>=1){
			int aux=A[i>>1];
			A[i>>1]=f(A[i], A[i^1]);
			if(aux==A[i>>1]) break;
		}
	}
	int que(int l, int r){
		int ans=neutro;
		for(l += N, r += N;l<r; l>>=1, r>>=1){
			if(l & 1) ans=f(ans, st.A[l++]);
			if(r & 1) ans=f(ans, st.A[--r]);
		}
		return ans;
	}
} st;
