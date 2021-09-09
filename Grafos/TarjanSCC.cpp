int n, temp, cont;
vi adj[N], SCC[N], adjSCC[N];
bool vis[N];
int low[N], disc[N], belong[N];
stack<int> S;
 
void dfs(int v) {
	disc[v] = low[v] = ++temp;
	S.push(v);
	vis[v] = 1;
	for(int u: adj[v]) {
		if(!disc[u])
			dfs(u);
		if(vis[u])
			low[v] = min(low[u], low[v]);
	}
	if(disc[v] == low[v]) {
		while(1) {
			int u = S.top();
			S.pop();
			vis[u] = 0;
			belong[u] = cont;
			SCC[cont].pb(u);
			if(u == v) break;
		}
		cont++;
	}
}
 
void tarjan() {
	For(i,0,n)
		if(!disc[i])
			dfs(i);
	For(i,0,cont) {
		for(int u: SCC[i])
			for(int v: adj[u]) if(belong[v] != i) {
				adjSCC[i].pb(belong[v]);
			}
		sort(all(adjSCC[i]));
		adjSCC[i].resize(unique(all(adjSCC[i])) - adjSCC[i].begin());
	}
}
