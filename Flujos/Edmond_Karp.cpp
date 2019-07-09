vii adj[N];
ii cap[2*N*N];
int p[N];
int n, m; 

lli bfs(int s, int t){
	rep(i,1,n+1) p[i]=-1;
	p[s]=-2;
	queue<ii> Q;
	Q.push(mp(s,INF));
	while(!Q.empty()){
		int v = Q.front().fst;
		lli f = Q.front().snd;
		Q.pop();
		for(ii u: adj[v]){
			if(p[u.fst]==-1 && cap[u.snd].fst){
				p[u.fst]=u.snd;
				int nf = min(f, cap[u.snd].fst);
				if(u.fst==t){
					return nf;
				}
				Q.push(mp(u.fst, nf));
			}
		}
	}
	return 0;
}

lli maxflow(int s, int t){
	lli flow=0;
	lli nflow;
	while(nflow=bfs(s, t)){
		flow+=nflow;
		int cur=t;
		while(cur!=s){
			cap[p[cur]].fst-=nflow;
			cap[p[cur]^1].fst+=nflow;
			cur = cap[p[cur]].snd;
		}
	}
	return flow;
}

int main(){
    fastio;
	cin>>n>>m;
	int u, v, w;
	int cont=0;
	while(m--){
		cin>>u>>v>>w;
		rep(i,0,2){
			adj[u].pb(mp(v,cont));
			adj[v].pb(mp(u,cont+1));
			cap[cont]=mp(w,u);
			cap[cont+1]=mp(0,v);
			cont+=2;
			swap(u,v);
		}
	}
	cout<< maxflow(1, n) << endl;
    return 0;
}
