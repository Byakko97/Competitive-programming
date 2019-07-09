vi adj[N];
vi SCC[N];
set<int> adj2[N];
int cont;
bool vis[N];
int low[N];
int disc[N];
int belong[N];
stack<int> S;
int tm;

void tarjan(int v){
	int u;
	disc[v]=low[v]=++tm;
	S.push(v);
	vis[v]=1;
	for(int u: adj[v]){
		if(!disc[u])
			tarjan(u);
		if(vis[u])
			low[v]=min(low[u], low[v]);
	}
	if(disc[v]==low[v]){
		while(1){
			u = S.top();
			S.pop();
			vis[u]=0;
			belong[u]=cont;
			SCC[cont].pb(u);
			if(u==v) break;
		}
		cont++;
	}
}

int main(){
	tarjan(root);
	rep(i, 0, cont)
		for(int u: SCC[i])
			for(int v: adj[u]) if(belong[v]!=i)
				adj2[i].insert(belong[v]);
}
