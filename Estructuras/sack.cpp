void sack(int v=1, int p=0, bool keep=1){
	int bigC=-1, mx=-1;
	for(int u: adj[v]) if(u!=p && sz[u]>mx){
		mx=sz[u];
		bigC=u;
	}
	for(int u: adj[v]) if(u!=p && u!=bigC) sack(u, v, 0);
	if(bigC!=-1) sack(bigC, v, 1);
	for(int u: adj[v]) if(u!=p && u!=bigC)
		rep(t, in[u], out[u]) cnt[C[cur[t]]]++;
	cnt[C[v]]++;
	//queries
	if(!keep) rep(t, in[v], out[v]) cnt[C[cur[t]]]--;
}
