struct Trie{
	int t[N][26], exit[N], tam[N], pos[N], link[N], nxt=1;
	inline void add(const string& s, int p){
		int v=0;
		for(int i=0; i<sz(s); i++){
			if(!t[v][s[i]]){
				t[v][s[i]]=nxt++;
				tam[nxt-1]=tam[v]+1;	
			}
			v = t[v][s[i]];
		}
		exit[v]=v;
		pos[v]=p;
	}
	inline void go(){
		queue<int> Q;
		Q.push(0);
		while(!Q.empty()){
			int v = Q.front();
			Q.pop();
			int l = link[v];
			if(!exit[v]) exit[v]=exit[l];
			for(int i=0; i<26; i++){
				if(t[v][i]){
					link[t[v][i]] = v? t[l][i]:0;
					Q.push(t[v][i]);
				}else t[v][i] = t[l][i];
			}				
		}
	}
	inline void clear(){
		for(int i=0; i<nxt; i++){
			exit[i]=0;
			tam[i]=0;
			for(int j=0; j<26; j++)
				t[i][j]=0;
		}
		nxt=1;
	}
} trie;
