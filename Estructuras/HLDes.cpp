//Implementar con segment tree

int gid, tam[N], id[N], p[N], d[N], rt[N];
vi adj[N];

int makesz(int v=0, int par=-1, int depth=0){
	tam[v]=1;
	p[v]=par;
	d[v]=depth;
	rep(i,0,sz(adj[v])){
		int u=adj[v][i];
		if(u!=par)
			tam[v]+=makesz(u, v, depth+1);
	}
	return tam[v];
}

void dfs(int v=0, int root=0){
	id[v]=gid++;
	rt[v]=root;
	int bigC=-1;
	int curt=0;
	rep(i,0,sz(adj[v])){
		int u = adj[v][i];
		if(u!=p[v] && tam[u]>curt){
			curt=tam[u];
			bigC=u;
		}
	}
	if(bigC!=-1) dfs(bigC, root);
	rep(i,0,sz(adj[v])){
		int u = adj[v][i]; 
		if(u!=p[v] && u!=bigC)
			dfs(u, u);
	}
}

void hldinit(){
	makesz();
	dfs();
}

void hldupdate(int v, int x){
	update(id[v], x);
}

int pathque(int u, int v){
	int ans=neutro();
	while(u!=-1){
		if(rt[u]==rt[v]){
			int a = id[u];
			int b = id[v];
			if(a>b) swap(a,b);
			ans = f(ans, que(a,b));
			u=-1;
		}else{
			if(d[rt[u]]>d[rt[v]]) swap(u,v);
			ans = f(ans, que(id[rt[v]], id[v]));
			v = p[rt[v]];
		}
	}
	return ans;
}
