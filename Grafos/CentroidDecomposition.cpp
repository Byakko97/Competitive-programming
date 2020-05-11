//Problema de ejemplo: Xenia and Tree (https://codeforces.com/problemset/problem/342/E)
//Dos tipos de queries: pintar un nodo y encontrar la distancia mas corta de un nodo especifico a uno pintado

const ll N=1e5+5;
const ll INF = 1e18;

ll tam[N], ans[N], distp[N][17], par[N], depth[N];
vi adj[N];

ll dfs(int v=0, int p=-1, int dep=0, int d=1){
	tam[v]=1;
	distp[v][dep]=d;
	for(int u: adj[v]) if(u!=p && par[u]==-1)
		tam[v]+=dfs(u,v,dep,d+1);
	return tam[v];
}

void centroid(int v=0, int p=-2, int t=tam[0], ll dep=0){
	for(int u: adj[v]) if(par[u]==-1 && (2*tam[u]>t)){
		tam[v]=0; centroid(u, p, t, dep); return;
	}
	par[v]=p, depth[v]=dep, distp[v][dep]=0;
	for(int u: adj[v]) if(par[u]==-1){
		dfs(u, v, dep);
		centroid(u,v,tam[u],dep+1);
	}	
}

void upd(int v){
	int u=v, d=depth[v];
	while(u!=-2){
		ans[u] = min(ans[u],distp[v][d]);
		u = par[u];
		d--;
	}
}

ll que(int v){
	ll cur = INF, d=depth[v], u=v;
	while(u!=-2){
		cur = min(ans[u]+distp[v][d],cur);	
		u = par[u];
		d--;
	}
	return cur;
}	

int main(){
	fastio;
	int n, m; cin>>n>>m;
	For(i,0,n-1){
		int u, v; cin>>u>>v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	For(i,0,n) par[i]=-1;
	dfs();
	centroid();
	For(i,0,n) ans[i]=INF;
	upd(0);
	while(m--){
		int t, v; cin>>t>>v; v--;
		if(t==1) upd(v);
		else cout << que(v) << endl;
	}
	return 0;
}

