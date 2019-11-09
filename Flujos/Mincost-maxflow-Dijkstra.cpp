struct MCF{
	int n, s, t, fl;
	ld cost;
	vi first, prev;
	vector<ld> dist;
	struct Edge{
		Edge(int _to, ll _cap, ld _cost, int _next):
			to(_to), cap(_cap), cost(_cost), next(_next) {};
		int to, next;
		ll cap;
		ld cost;
	};
	vector <Edge> g;
	MCF(int _n, int _s,int _t) :
		n(_n), s(_s), t(_t), fl(0), cost(0){
		first.resize(n,-1);
		dist.resize(n);
		prev.resize(n);
		g.reserve(n*n);
	};
	void add_edge(int u, int v, int cap, ld cost){
		g.pb(Edge(v,cap,cost,first[u]));
		first[u]=sz(g)-1;
		g.pb(Edge(u,0,-cost,first[v]));
		first[v]=sz(g)-1;
	}
	bool augment(){
		dist.assign(n,INF);
		dist[s]=0;
		priority_queue < pair<ld,int> > q;
		q.push(mp(0.0,s));
		while(sz(q)){
			if(dist[t]<INF) break; //comentar para pesos negativos
			pair<ld, int> top = q.top(); q.pop();
			if(fabs(dist[top.ss]+top.ff)>EPS) continue;
			int u = top.ss;
			for(int e = first[u]; e!=-1; e=g[e].next){
				int v = g[e].to;
				ld ndist=-top.ff + g[e].cost;
				if(g[e].cap>0 && dist[v]>ndist){
					dist[v]=ndist;
					q.push(mp(-ndist,v));
					prev[v]=e;
				}
			}
		}
		return dist[t]<INF;
	}
	pair<int, ld> get_flow(){
		while(augment()){
			ll cur=t, curf=INF;
			while(cur!=s){
				int e = prev[cur];
				curf = min(curf, g[e].cap);
				cur = g[e^1].to;
			}
			fl+=curf; cost+=(dist[t])*curf;
			cur=t;
			while(cur!=s){
				int e = prev[cur];
				g[e].cap-=curf;
				g[e^1].cap+=curf;
				cur = g[e^1].to;
			}
		}
		return mp(fl,cost);
	}
};
