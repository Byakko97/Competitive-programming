vii adj[N];
ii cap[2*N*N];
int p[N];
int n, m; 

ll bfs(int s, int t){
	For(i,0,n) p[i]=-1;
	p[s]=-2;
	queue<ii> Q;
	Q.push(mp(s,INF));
	while(!Q.empty()){
		int v = Q.front().ff;
		ll f = Q.front().ss;
		Q.pop();
		for(ii u: adj[v]){
			if(p[u.ff]==-1 && cap[u.ss].ff){
				p[u.ff]=u.ss;
				ll nf = min(f, cap[u.ss].ff);
				if(u.ff==t){
					return nf;
				}
				Q.push(mp(u.ff, nf));
			}
		}
	}
	return 0;
}

ll maxflow(int s, int t){
	ll flow=0;
	ll nflow;
	while(nflow=bfs(s, t)){
		flow+=nflow;
		int cur=t;
		while(cur!=s){
			cap[p[cur]].ff-=nflow;
			cap[p[cur]^1].ff+=nflow;
			cur = cap[p[cur]].ss;
		}
	}
	return flow;
}

int cont;
void add_edge(int u, int v, ll w){
	adj[u].pb(mp(v,cont));
	adj[v].pb(mp(u,cont+1));
	cap[cont]=mp(w,u);
	cap[cont+1]=mp(0,v);
	cont+=2;	
}

