int n;
vi adj[N];

struct LCA{
	int height[N];
	int first[N];
	int vis[N];
	vi stree;
	vi euler;
	void build(int root=0){
		dfs(root);
		stree.resize(2*sz(euler));
		rep(i, sz(euler), sz(stree)){
			stree[i]=euler[i-sz(euler)];
		}
		rip(i, sz(euler)-1, 1){
			stree[i]=f(stree[i<<1], stree[i<<1 | 1]);
		}
	}
	void dfs(int u, int h=0){
		vis[u]=1;
		height[u]=h;
		first[u]=sz(euler);
		euler.pb(u);
		for(int v: adj[u]){
			if(!vis[v]){
				dfs(v, h+1);
				euler.pb(u);
			}
		}
	}
	int f(int u, int v){
		return (height[u]<height[v])? u:v;
	}
	int query(int u, int v){
		if(u==v) return u;
		int l=first[u];
		int r=first[v];
		if(l>r) swap(l, r);
		r+=1;
		int ans=u;;
		for(l+=sz(euler), r+=sz(euler); l<r; l>>=1, r>>=1){
			if(l&1) ans=f(ans, stree[l++]);
			if(r&1) ans=f(ans, stree[--r]);
		}
		return ans;
	}
	void clear(){
		rep(i, 1, n+1){
			adj[i].clear();
			vis[i]=0;
		}
		euler.clear();
		stree.clear();
	}
};
