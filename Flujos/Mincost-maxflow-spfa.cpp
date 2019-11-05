struct edge { int dest;ll origcap, cap; ll cost; int rev; };

struct MCF {

    vector<edge> adj[N];
    ll dis[N], cost;
    int source, target, iter;
    ll cap;
    edge* pre[N];
    int queued[N];
    MCF (){}
    void add_edge(int from, int to, ll cap, ll cost) {
        adj[from].push_back(edge {to, cap, cap, cost, (int)sz(adj[to])});
        adj[to].push_back(edge {from,0, 0, -cost, (int)sz(adj[from]) - 1});
    }

    bool spfa() { 
        For(i,0,N) queued[i] = 0;
        fill(dis, dis + N, INF);
        queue<int> q;
        pre[source] = pre[target] = 0;
        dis[source] = 0;
        q.emplace(source);
        queued[source] = 1;
        while (!q.empty()) {
            int x = q.front();
           
            ll d = dis[x];
            q.pop();
            queued[x] = 0;
            for (auto& e : adj[x]) {
                int y = e.dest;
                ll w = d + e.cost;
                if (e.cap < 1 || dis[y] <= w) continue;
                dis[y] = w;
                pre[y] = &e;
                if(!queued[y]){
                	q.push(y);
                	queued[y] = 1;
                }
            }
        }
        edge* e = pre[target];
        
        if (!e) return 0; 
        while (e) {
            edge& rev = adj[e->dest][e->rev];
            e->cap -= cap;
            rev.cap += cap;
            cost += cap * e->cost;
            e = pre[rev.dest];
        }
        return 1;
    }

    ii mincost(int S, int T) {
        cap = 1, source = S, target = T, cost = 0;
        while(spfa()) {}
        ll totflow = 0;
        for(auto e: adj[source]){
            totflow += (e.origcap - e.cap);
        }
        return mp(totflow, cost);
    }
};
