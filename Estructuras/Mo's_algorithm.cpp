//Problema de ejemplo: Winning ways 2
//https://www.codechef.com/problems/MDSWIN2

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=1e5+5;
const ll MOD = 998244353;

ll f[N], invf[N], A[N];

ll binpow(ll n, ll p){
	if(p==0) return 1;
	ll cur = binpow(n,p>>1);
	cur=(cur*cur)%MOD;
	if(p&1) cur= (cur*n)%MOD;
	return cur;
}

ll inv(int n){
	return binpow(n,MOD-2);
}

void prec(){
	f[0]=1;
	invf[0]=1;
	For(i,1,N){
		f[i]=(f[i-1]*i)%MOD;
		invf[i] = inv(f[i]);
	}
}

ll comb(ll n, ll k){
	return (((f[n]*invf[k])%MOD)*invf[n-k])%MOD;
}


ll c[N], cc[N];
vi V, temp;
ll xorval;
bool in[N];
//Mo
int b_size;

bool comp(pair<ii, int> a, pair<ii, int> b){
	return (a.ff.ff/b_size != b.ff.ff/b_size ) ? a.ff.ff<b.ff.ff : a.ff.ss>b.ff.ss;
}

void add(int i){
	xorval = xorval^c[A[i]];
	cc[c[A[i]]]--;
	c[A[i]]++;
	xorval = xorval^c[A[i]];
	cc[c[A[i]]]++;
	if(!in[c[A[i]]]){
		V.pb(c[A[i]]);
		in[c[A[i]]]=1;
	}
}

void rem(int i){
	xorval = xorval^c[A[i]];
	cc[c[A[i]]]--;
	c[A[i]]--;
	xorval = xorval^c[A[i]];
	cc[c[A[i]]]++;
	if(!in[c[A[i]]]){
		V.pb(c[A[i]]);
		in[c[A[i]]]=1;
	}
}

ll get(){
	ll ans=0;
	for(auto x: V) if(cc[x]==0){
			in[x]=0;
		}else{
			ll d = x^xorval;
			if(d<x) ans = (((comb(x,d)*cc[x])%MOD)+ans)%MOD;
			temp.pb(x);				
		}
	V = temp;
	temp.clear();
	return ans;
}
//fin Mo

ll ans[N];

int main(){
	fastio;
	int t; cin>>t;
	vi nums;
	map<int, int> conv;
	vector<pair<ii, int> > queries;
	prec();
	while(t--){
		int n; cin>>n;
		b_size = (int)sqrt(n+ .0) + 1;
		xorval=0;
		For(i,0,n) c[i]=cc[i]=in[i]=0;
		For(i,0,n){
			cin>>A[i];
			nums.pb(A[i]);
		}
		sort(all(nums));
		nums.resize(unique(all(nums))-nums.begin());
		For(i,0,n) conv[nums[i]]=i;
		For(i,0,n) A[i]=conv[A[i]];
		int q; cin>>q;
		For(i,0,q){
			int l, r; cin>>l>>r; l--, r--;
			queries.pb(mp(mp(l,r),i));
		}
    //Mo
		sort(all(queries), comp);
		int curl=0, curr=-1;
		for(auto q: queries){
			int l = q.ff.ff;
			int r = q.ff.ss;
			while(curl > l)
				add(--curl);
			while(curr < r)
				add(++curr);
			while(curl < l)
				rem(curl++);
			while(curr > r)
				rem(curr--);
			ans[q.ss]=get();
		}
    //Fin mo
		For(i,0,q)
			cout << ans[i] << endl;
		nums.clear();
		queries.clear();
		V.clear();
	}
	return 0;
}
