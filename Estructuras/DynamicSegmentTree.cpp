//Problem: Periodic RMQ Problem. https://codeforces.com/contest/803/problem/G
//Bonus: Lazy propagation and Sparse table

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const int N = 1<<17;
const int LOGN = 18;
const int MAXNODES = 1e7+5;

int spt[N][LOGN];
int logt[N];

int _n, k;

struct ST{
	int val=-1, left=-1, right=-1;
	int lazy=0;
	bool leaf;
} pool[MAXNODES];

int nxt=0;

inline int create(int l, int r){
	pool[nxt].leaf = l+1==r;
	int lg;
	if(l+_n<=r){
		lg = logt[_n];
		pool[nxt].val = min(spt[0][lg], spt[_n-(1<<lg)][lg]);
	}else if(l/_n == r/_n){
		l%=_n, r%=_n;
		lg = logt[r-l];
		pool[nxt].val = min(spt[l][lg],spt[r-(1<<lg)][lg]);
	}else{
		l%=_n, r%=_n;
		lg = logt[_n-l];
		pool[nxt].val = min(spt[l][lg], spt[_n-(1<<lg)][lg]);
		if(r){
			lg = logt[r];
			pool[nxt].val = min(min(spt[0][lg], spt[r-(1<<lg)][lg]),pool[nxt].val);
		}
	}
	return nxt++;
}

inline int left(const int n, const int l, const int r){
	return pool[n].left!=-1 ? pool[n].left : (pool[n].left=create(l,r));
}

inline int right(const int n, const int l, const int r){
	return pool[n].right!=-1 ? pool[n].right: (pool[n].right=create(l,r));
}

inline void propagate(const int n, const int a, const int b){
	pool[n].val=pool[n].lazy;
	int m = (a+b)>>1;
	if(!pool[n].leaf){
		pool[left(n,a,m)].lazy = pool[n].lazy;
		pool[right(n,m,b)].lazy = pool[n].lazy;
	}
	pool[n].lazy=0;
}

int que(const int A, const int B, const int n=0, const int a=0, const int b=_n*k){
	if(pool[n].lazy) propagate(n, a, b);
	if(A<=a && b<=B) return pool[n].val;
	if(b<=A || B<=a) return INT_MAX;
	int m = (a+b)>>1;
	return min(que(A, B, left(n, a, m), a, m), que(A, B, right(n, m, b), m, b));
}

void upd(const int A, const int B, const int x, const int n=0, const int a=0, const int b=_n*k){
	if(pool[n].lazy) propagate(n, a, b);
	if(b<=A || B<=a) return;
	if(A<=a && b<=B){
		pool[n].lazy=x;
		propagate(n, a, b);
		return;
	}
	int m = (a+b)>>1;
	upd(A, B, x, left(n, a, m), a, m);
	upd(A, B, x, right(n, m, b), m, b);
	pool[n].val = min(pool[left(n, a, m)].val, pool[right(n, m, b)].val);
}

int main(){
	fastio;
	cin>>_n>>k;
	For(i,0,_n){
		cin>>spt[i][0];
	}
	for(int pw=1, lg=0; pw<=_n; pw<<=1, lg++){
		For(i,pw,min(pw<<1,_n+1)){
			logt[i]=lg;
		}
	}
	ll q; cin>>q;
	For(_k,1,LOGN){
		for(int i=0; i+(1<<_k)<=_n; i++){
			spt[i][_k]=min(spt[i][_k-1],spt[i+(1<<(_k-1))][_k-1]);
		}
	}
	create(0,_n*k);
	while(q--){
		int tq, l, r; cin>>tq>>l>>r; --l; 
		int x;
		if(tq==2) cout<<que(l, r)<<endl;
		else{
			cin>>x;
			upd(l,r,x);
		}
	}
	return 0;
}
