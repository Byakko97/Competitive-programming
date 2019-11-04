const ll INF = 1e10;

struct MCF{
	int n;
	vector<ll> prio, curflow, prevedge, prevnode, pot;
	priority_queue<ll, vector<ll>, greater<ll> > q;
	struct edge{int to, rev; ll f, cap, cost;};
	vector<vector<edge> > g;
	MCF(int n):n(n), prio(n), curflow(n), prevedge(n), prevnode(n), pot(n), g(n){}
	void add_edge(int s, int t, ll cap, ll cost){
		g[s].pb((edge){t,sz(g[t]),0,cap,cost});
		g[t].pb((edge){s,sz(g[s])-1,0,0,-cost});
	}
	pair<ll,ll> get_flow(int s, int t){
		ll flow=0, flowcost=0, bestcost=0;
		while(1){
			q.push(s);
			For(i,0,n) prio[i]=INF;
			prio[s]=0; curflow[s]=INF;
			while(!q.empty()){
				ll cur = q.top();
				int d = cur>>32, u=cur;
				q.pop();
				if(d!=prio[u]) continue;
				For(i,0,sz(g[u])){
					edge &e = g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					ll nprio = prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio){
						prio[v]=nprio;
						q.push(((ll)nprio<<32)+v);
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INF) break;
			For(i,0,n) pot[i]+=prio[i];
			ll df=min(curflow[t], INF-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]){
				edge &e = g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return mp(flow,flowcost);
	}
};
