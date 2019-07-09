void dfs(int u, int p){
	up[u][0]=p;
	tin[u] = ++tm;
	rep(i, 1, 11) //log(n)
		up[u][i] = up[up[u][i-1]][i-1];
	
	for(int v: adj[u]) if(v!=p)
		dfs(v, u);
	tout[u]=++tm;
}

bool check(int u, int v){
	return tin[v]>=tin[u] && tout[v]<=tout[u];
}

int lca(int u, int v){
	if(check(u, v)) return u;
	if(check(v, u)) return v;
	rip(i, 10, 0)
		if(!check(up[u][i], v)) u = up[u][i];
	return up[u][0];
}
