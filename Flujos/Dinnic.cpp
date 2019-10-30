//Gracias al vasito

struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,sz(g[t]),0,cap});
		g[t].pb((edge){s,sz(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		For(i,0,sz(dist)) dist[i]=-1;
		dist[src]=0;
		int qt=0;q[qt++]=src;
		For(qh,0,qt){
			int u=q[qh];
			For(i,0,sz(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<sz(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			For(i,0,sz(work)) work[i]=0;
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};
