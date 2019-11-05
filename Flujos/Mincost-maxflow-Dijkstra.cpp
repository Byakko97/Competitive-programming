struct MCF{
    int n,s,t,fl,cost;
    vi first,prev,dist;
    struct Edge {
        Edge(int _to,int _cap,int _cost,int _next) : to(_to), cap(_cap), cost(_cost), next(_next) {};
        int to,next,cap,cost;
    };
    vector <Edge> g;
    MCF(int _n,int _s,int _t) : n(_n), s(_s), t(_t), fl(0), cost(0) {
        first.resize(n,-1);
        dist.resize(n);
        prev.resize(n);
        g.reserve(8*n);
    };
    void add_edge(int u,int v,int cap,int cost) {
        g.push_back(Edge(v,cap,cost,first[u])); first[u]=g.size()-1;
        g.push_back(Edge(u,0,-cost,first[v])); first[v]=g.size()-1;
    }
    bool augment() {
        dist.assign(n,INF);
        dist[s]=0;
        priority_queue < ii > q; q.push(make_pair(0,s));
        while(sz(q)) {
            if (dist[t]!=INF) break;
            ii top=q.top(); q.pop();
            if (dist[top.ss]!=-top.ff) continue;
            int u=top.ss;
            for(int e=first[u];e!=-1;e=g[e].next) {
                int v=a[e].to,ndist=-top.ff+a[e].cost;
                if (a[e].cap>0&&dist[v]>ndist) {
                    dist[v]=ndist;
                    q.push(mp(-ndist,v));
                    prev[v]=e;
                }
            }
        }
        return dist[t]!=inf;
    }
    ii get_flow() {
        while(augment()) {
            int cur=t,curf=INF;
            while(cur!=s) {
                int e=prev[cur];
                curf=min(curf,g[e].cap);
                cur=g[e^1].to;
            }
            fl+=curf; cost+=(dist[t])*curf;
            cur=t;
            while(cur!=s) {
                int e=prev[cur];
                g[e].cap-=curf;
                g[e^1].cap+=curf;
                cur=a[e^1].to;
            }
        }
        return mp(fl,cost);
    }
};
 
