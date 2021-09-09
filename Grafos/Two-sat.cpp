// Useful when negation of atomic expression is given as a negative number
int conv(int x) {
	if(x > 0) return (x - 1) << 1;
	else return (-x - 1) << 1 | 1;
}
 
vi adj[N], adjt[N];
 
void add_edge(int u, int v) {
	adj[u].pb(v);
	adjt[v].pb(u);
}
 
void add_prop(int u, int v) {
	u = conv(u), v = conv(v);
	add_edge(u^1, v);
	add_edge(v^1, u);
}
 
bool vis[N];
int comp[N];
stack<int> order;
 
void toposort(int v) {
	vis[v] = 1;
	for(int u: adj[v]) if(!vis[u])
		toposort(u);
	order.push(v);
}
 
void mark(int v, int id) {
	comp[v] = id;
	for(int u: adjt[v]) if(comp[u] == -1)
		mark(u, id);
}
 
bool two_sat(int n) {
	For(i,0,n<<1)
		comp[i<<1] = comp[i<<1|1] = -1;
	For(i,0,n<<1) if(!vis[i])
		toposort(i);
	int cont = 0;
	For(i,0,n<<1) {
		int v = order.top();
		order.pop();
		if(comp[v] == -1)
			mark(v, cont++);
	}
	For(i,0,n)
		if(comp[i<<1] == comp[i<<1|1])
			return 0;
	return 1;
}
