//Recuerda que tenemos nodos blocks (las componentes biconexas) y nodos cuts (puntos de articulacion)
//los primeros univocamente representados por un set de aristas

int n, m, t;
int belong[N], low[N], disc[N], pai[N];
bool vis[N], AP[N], bicon[N];
int cont;
vii adj[N];
vi adj2[N];

stack<int> St;
ii edge[N];

int edgeBelong[N];

void bcc(int v){
	vis[v]=1;
	low[v]=disc[v]=t++;
	int child=0;
	if(sz(adj[v])==0) AP[v]=1;
	for(ii u: adj[v]){
		if(!vis[u.ff]){
			child++;
			St.push(u.ss);
			pai[u.ff]=v;
			bcc(u.ff);
			low[v]=min(low[v],low[u.ff]);
			if(low[u.ff]>=disc[v]){
				if(pai[v]!=-1 || child>1) AP[v]=1;
				while(1){
					int e = St.top();
					St.pop();
					edgeBelong[e]=cont;
					if(!AP[edge[e].ff]){
						belong[edge[e].ff]=cont;
					}
					if(!AP[edge[e].ss]){
						belong[edge[e].ss]=cont;
					}
					if(e==u.ss) break;
				}
				cont++;
			}
		}else if(u.ff!=pai[v]){
			low[v] = min(low[v],disc[u.ff]);
			if(disc[u.ff]<disc[v])
				St.push(u.ss);
		}
	}
}

int main(){
	fastio;
	cin>>n>>m;
	For(i,0,m){
		int u, v; cin>>u>>v;
		u--, v--;
		adj[u].pb(mp(v,i));
		adj[v].pb(mp(u,i));
		edge[i]=mp(u,v);
	}
	For(i,0,n) pai[i]=-1;
	For(i,0,n) if(!vis[i]){
		bcc(i);
	}
	For(i,0,cont) bicon[i]=1;
	For(i,0,n) if(AP[i]){
		for(ii u: adj[i]){
			adj2[cont].pb(edgeBelong[u.ss]);
			adj2[edgeBelong[u.ss]].pb(cont);
		}
		belong[i]=cont;
		cont++;
	}
	For(i,0,cont){
		sort(all(adj2[i]));
		adj2[i].resize(unique(all(adj2[i]))-adj2[i].begin());
	}
  return 0;
}
