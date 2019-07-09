Ejemplo:
Invertir unos y ceros en rango. Consultar cantidad de unos en rango.

struct nodo{
	int on, tam;
};

struct segTree{
	int n, h, d[N];
	nodo A[2*N];
	void init(){
		h = sizeof(int) * 8 - __builtin_clz(n);
		rep(i, 0, n) A[i+n].tam=1;
		rip(i,n-1,1) A[i].tam=A[i<<1].tam+A[i<<1|1].tam;
	}

	void apply(int p){
		A[p].on = A[p].tam - A[p].on;
		if(p<n) d[p]=d[p]^1;
	}

	void push(int p){
		for(int s=h; s>0; s--){
			int i= p>>s;
			if(d[i]){
				apply(i<<1);
				apply(i<<1|1);
				d[i]=0;
			}
		}
	}

	void build(int p){
		while(p>1){
			p>>=1;
			if(!d[p]) A[p].on=A[p<<1].on+A[p<<1|1].on;
			else A[p].on=A[p].tam-(A[p<<1].on+A[p<<1|1].on);
		}
	}

	void upd(int l, int r){
		l+=n, r+=n;
		int l0=l, r0=r;
		push(l);
		push(r-1);
		for(; l<r; l>>=1, r>>=1){
			if(l&1) apply(l++);
			if(r&1) apply(--r);
		}
		build(l0);
		build(r0-1);
	}

	int que(int l, int r){
		l+=n, r+=n;
		push(l);
		push(r-1);
		int ans=0;
		for(; l<r; l>>=1, r>>=1){
			if(l&1) ans+=A[l++].on;
			if(r&1) ans+=A[--r].on;
		}
		return ans;
	}
  
	void print(){
		rep(i,1,2*n){
			trace(i);
			trace(A[i].on);
			if(i<n) trace(d[i]);
		}
	}
} st;

int main(){
    fastio;
    int m;
	cin>>st.n>>m;
	st.init();
	while(m--){
		int tq, l, r;
		cin>>tq>>l>>r;
		if(tq) cout<<st.que(--l, r)<<endl;
		else st.upd(--l, r);
		//st.print();
	}
    return 0;
}
