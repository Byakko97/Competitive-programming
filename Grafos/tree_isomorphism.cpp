const ll MOD = 1e18+7;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<int>(a,b)(rng);}

vi adj[N];
int tam[N];

int make(int v=0, int p=-1){
	tam[v]=1;
	for(int u: adj[v]) if(u!=p)
		tam[v] += make(u,v);
	return tam[v];
}

int getroot(function<bool(int,int)> comp){
	make();
	int center = 0;
	int t = tam[0];
	while(1){
		int nxt = -1;
		for(int u: adj[center])
			if(comp(t,2*tam[u])) nxt = u;
		tam[center]=0;
		if(nxt==-1) break;
		center = nxt;
	}
	return center;
}

unordered_map<ll, ll> M;

ll sum(ll a, ll b){
	ll ans = a+b;
	return ans>=MOD? ans:(ans-MOD);
}

ll dfs(int v, int p=-1){
	ll ans = 0;
	for(int u: adj[v]) if(u!=p)
		ans = sum(ans,dfs(u,v));
	return M.count(ans)? M[ans]:(M[ans]=random(0,MOD-1));
}

array<ll,2> solve(int n){
	For(i,0,n-1){
		int x, y; cin>>x>>y; x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	array<ll, 2> ans;
	ans[0] = dfs(getroot(less<int>()));
	ans[1] = dfs(getroot(less_equal<int>()));
	For(i,0,n) adj[i].clear();
	return ans;
}

int main(){
	fastio;
	int t; cin>>t;
	array<ll,2> ans[2];
	string res[2] = {"NO","YES"};
	while(t--){
		int n; cin>>n;
		For(i,0,2) ans[i] = solve(n);
		bool check = 0;
		For(i,0,2) For(j,0,2) check |= ans[0][i]==ans[1][j];
		cout << res[check] << '\n';
	}
	return 0;
}
