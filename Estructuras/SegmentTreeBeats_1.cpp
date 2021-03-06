struct nodo{
	ll cantMay, may, second, sum;
	bool leaf, lazy;
} t[N*4];

int A[N];

void build(int nodo){
	t[nodo].may = max(t[nodo<<1].may,t[nodo<<1|1].may);
	t[nodo].sum = t[nodo<<1].sum + t[nodo<<1|1].sum;
	if(t[nodo<<1].may == t[nodo<<1|1].may){
		t[nodo].cantMay = t[nodo<<1].cantMay + t[nodo<<1|1].cantMay;
		t[nodo].second = max(t[nodo<<1].second,t[nodo<<1|1].second);
	}else if(t[nodo<<1].may > t[nodo<<1|1].may){
		t[nodo].cantMay = t[nodo<<1].cantMay;
		t[nodo].second = max(t[nodo<<1|1].may,t[nodo<<1].second);
	}else{
		t[nodo].cantMay = t[nodo<<1|1].cantMay;
		t[nodo].second = max(t[nodo<<1].may,t[nodo<<1|1].second);
	}
}

void init(int l, int r, int nodo=1){
	t[nodo].lazy = 0;
	t[nodo].leaf = 0;
	if(l==r){
		t[nodo].cantMay=1;
		t[nodo].sum = t[nodo].may = A[l];
		t[nodo].second=-1;
		t[nodo].leaf=1;
		return;
	}
	int m = (l+r)>>1;
	init(l,m,nodo<<1);
	init(m+1,r,nodo<<1|1);
	build(nodo);
}

void puttag(int nodo, ll x){
	t[nodo].lazy =  1;
	t[nodo].sum -= (t[nodo].may-x)*t[nodo].cantMay;
	t[nodo].may = x;
}

void propagate(int nodo){
	if(!t[nodo].leaf){
		if(t[nodo<<1].may > t[nodo].may)
			puttag(nodo<<1,t[nodo].may);
		if(t[nodo<<1|1].may > t[nodo].may)
			puttag(nodo<<1|1,t[nodo].may);
	}
	t[nodo].lazy = 0;
}

// Queries maximum in closed range [ll, rr]
int queMax(int ll, int rr, int l=0, int r=n-1, int nodo=1){
	if(ll <= l && r <= rr) return t[nodo].may;
	if(rr < l || r < ll) return -1;
	if(t[nodo].lazy) propagate(nodo);
	int m = (l+r)>>1;
	return max(queMax(ll,rr,l,m,nodo<<1),queMax(ll,rr,m+1,r,nodo<<1|1));
}


// Queries sum of closed range [ll, rr]
ll queSum(int ll, int rr, int l=0, int r=n-1, int nodo=1){
	if(ll <= l && r <= rr) return t[nodo].sum;
	if(rr < l || r < ll) return 0;
	if(t[nodo].lazy) propagate(nodo);
	int m = (l+r)>>1;
	return queSum(ll,rr,l,m,nodo<<1)+queSum(ll,rr,m+1,r,nodo<<1|1);
}


// Updates to the minimum between x and current value in the closed range [ll, rr]
void upd(int ll, int rr, long long int x, int l=0, int r=n-1, int nodo=1){
	if(rr<l || r < ll || t[nodo].may <= x)
		return;
	if(ll<=l && r<=rr && t[nodo].second<x){
		puttag(nodo,x);return;
	}
	if(t[nodo].lazy) propagate(nodo);
	int m = (l+r)>>1;
	upd(ll,rr,x,l,m,nodo<<1);
	upd(ll,rr,x,m+1,r,nodo<<1|1);
	build(nodo);
}
