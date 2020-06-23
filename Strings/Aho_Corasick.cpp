struct Trie{
	int t[N][63], exit[N], pos[N], link[N], deg[N], nxt=1;
	vi adj[N];
	inline void add(const vector<int>& s, int p){
		int v = 0;
		for(int c: s)
			v = t[v][c] ? t[v][c]:(t[v][c]=nxt++);
		exit[v]=v;
		ind[p]=v;
	}
	inline void prec(){
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int v = Q.front();
			Q.pop();
			int l = link[v];
			if(!exit[v]) exit[v]=exit[l];
			adj[v].pb(l);
			deg[l]++;
			For(i,0,63){
				if(t[v][i]){
					link[t[v][i]] = v? t[l][i]:0;
					Q.push(t[v][i]);
				}else t[v][i]=t[l][i];
			}
		}
	}
	inline void que(const vector<int>& text){
		int v = 0;
		for(int c: text){
			v = t[v][c];
			ans[exit[v]]++;
		}
	}
	inline void push(){
		queue<int> Q;
		For(i,0,nxt) if(deg[i]==0)
			Q.push(i);
		while(!Q.empty()){
			int v = Q.front();
			Q.pop();
			for(int u: adj[v]){
				ans[u]+=ans[v];
				deg[u]--;
				if(deg[u]==0) Q.push(u);
			}
		}
	}
} trie;
