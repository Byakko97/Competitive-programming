//Ejemplo con maximo valor en arista. Cambios simples en update y queries para que los valores sean en vertices

int gid, tam[N], id[N], p[N], d[N], rt[N];
vi adj[N];

int makesz(int v=0, int par=-1, int depth=0){
	tam[v]=1;
	p[v]=par;
	d[v]=depth;
	for(int u: adj[v]) if(u!=par)
		tam[v]+=makesz(u,v,depth+1);
	return tam[v];
}

void dfs(int v=0, int root=0){
	id[v]=gid++;
	rt[v]=root;
	if(sz(adj[v])>1 && adj[v][0]==p[v]) swap(adj[v][0],adj[v][1]);
	for(auto &u: adj[v]) if(u!=p[v] && tam[u]>tam[adj[v][0]])
		swap(adj[v][0],u);
	for(auto u:adj[v]) if(u!=p[v])
		dfs(u, u==adj[v][0]? root:u);
}

void hldinit(){
	gid=0;
	makesz();
	dfs();
	st.init(gid);
}

void hldupdate(int u, int v, int x){
	if(d[u]<d[v]) swap(u,v); //por ser arista
	st.upd(id[u],x);
}

int pathque(int u, int v){
	assert(u!=v);
	int ans=-1;
	while(u!=-1){
		if(rt[u]==rt[v]){
			int a = id[u], b = id[v];
			ans = max(ans, st.que(min(a,b)+1,max(a,b))); //por ser arista
			u=-1;
		}else{
			if(d[rt[u]]>d[rt[v]]) swap(u,v);
			ans = max(ans, st.que(id[rt[v]], id[v]));
			v = p[rt[v]];
		}
	}
	return ans;
}
