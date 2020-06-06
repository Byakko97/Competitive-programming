vector<pair<char, ii> > queries;
set<ii> activeEdges;
set<ii> blockEdges;

int p[N];
bool vis[N];
vi adj[N];

void dfs(int u){
	vis[u]=1;
	for(int v: adj[u]) if(!vis[v])
		dfs(v);
}

int find(int x){
	return p[x]==x ? x: (p[x]=find(p[x]));
}

void uni(int u, int v){
	p[find(u)]=find(v);
}

int main(){
	fastio;
	int n; cin>>n;
	int m; cin>>m;
	int b_size = sqrt(m +.0) +1; 
	string s;
	int u, v;
	For(i,0,m){
		cin>>s>>u>>v;
		u--,v--;
		if(u>v) swap(u,v);
		queries.pb(mp(s[0],mp(u,v)));
	}
	for(int i=0; i<m; i+=b_size){
		For(i,0,n) p[i]=i;
		For(j,i,min(i+b_size,m)) if(queries[j].ff!='c')
			if(activeEdges.count(queries[j].ss)){
				activeEdges.erase(queries[j].ss);
				blockEdges.insert(queries[j].ss);
			}
		for(ii edge : activeEdges)
			uni(edge.ff,edge.ss);
		For(j,i,min(i+b_size,m)){
			if(queries[j].ff=='a') blockEdges.insert(queries[j].ss);
			else if(queries[j].ff=='r'){ 
				if(blockEdges.count(queries[j].ss)) blockEdges.erase(queries[j].ss);
			}else{
				for(ii edge: blockEdges){
					u = find(edge.ff), v = find(edge.ss);
					adj[u].pb(v);
					adj[v].pb(u);
				}
				u = find(queries[j].ss.ff), v = find(queries[j].ss.ss);
				dfs(u);
				cout << (vis[v] ? "YES":"NO") << endl;
				vis[u]=0;
				for(ii edge: blockEdges){
					u = find(edge.ff), v = find(edge.ss);
					adj[u].clear();
					adj[v].clear();
					vis[u]=vis[v]=0;
				}
			}
		}
		for(ii edge: blockEdges)
			activeEdges.insert(edge);
		blockEdges.clear();
	}
	return 0;
}

