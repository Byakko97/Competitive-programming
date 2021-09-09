// Update: add in position
// Query: sum in range

struct segTree{
	vi t = vi(1,0), left = vi(1,0), right = vi(1,0);
	static int n;
	int new_node(int v, int l=0, int r=0){
		t.pb(v), left.pb(l), right.pb(r);
		return sz(t)-1;
	}
	int init(int* A, int L=0, int R=n){
		if(L+1 == R) return new_node(A[L]);
		int M = (L+R)>>1;
		int l = init(A, L, M), r = init(A, M, R);
		return new_node(t[l] + t[r], l , r);
	}
	int upd(int k, int pos, int v, int L=0, int R=n){
		int nxt = new_node(t[k], left[k], right[k]);
		if(L+1 == R) t[nxt] += v;
		else{
			int M = (L+R) >> 1;
			int temp;
			if(pos < M) temp = upd(left[nxt], pos, v, L, M), left[nxt] = temp;
			else temp = upd(right[nxt], pos, v, M, R), right[nxt] = temp;
			t[nxt] = t[left[nxt]] + t[right[nxt]];
		}
		return nxt;
	}
	int que(int k, int l, int r, int L=0, int R=n){
		if(r <= L || R <= l) return 0;
		if(l <= L && R <= r) return t[k];
		int M = (L+R) >> 1;
		return que(left[k], l, r, L, M)+que(right[k], l, r, M, R);
	}
};
int segTree::n = N;
