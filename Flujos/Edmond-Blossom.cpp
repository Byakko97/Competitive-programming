struct EB{
	ll n; vi M, vst; set<ii> used;
	void join(ll a, ll b){ M[a]=b; M[b]=a;}
	bool dfs(ll k, vector<vi>&com, vi &B){
		vst[k]=0;
		For(i,0,n) if(com[k][i]){
			if(vst[i]==-1){
				vst[i]=1;
				if(M[i]==-1 || dfs(M[i], com, B)){
					join(k,i);
					return true;
				}
			}
			if(vst[i]==0 || sz(B)){
				B.pb(i), B.pb(k);
				if(k==B[0]){ M[k]==-1; return true;}
				return false;
			}
		}
		return false;
	}
	bool augment(vector<vi> &com){
		For(m,0,n) if(M[m]==-1){
			vi B; vst = vi(n, -1);
			if(!dfs(m, com, B)) continue;
			if(!sz(B)) return true;
			ll ref = B[0], s=sz(B);
			vector<vi> cur = com;
			For(i,1,s-1) For(j,0,n)
				cur[ref][j]=cur[j][ref]|=com[B[i]][j];
			For(i,1,s-1) For(j,0,n){
				cur[B[i]][j] = cur[j][B[i]]=0;
			}
			cur[ref][ref]=0;
			if(!augment(cur)) return false;
			ll k = M[ref];
			if(k!=-1) For(i,0,s) if(com[B[i]][k]){
				join(B[i],k);
				if(i&1) for(ll j=i+1; j<s; j+=2){
					join(B[j], B[j+1]);
				}else for(ll j=0; j<i; j+=2)
					join(B[j], B[j+1]);
				break;
			}		
			return true;
		}
		return false;
	}
	ll edmonds(vector<vi> &com){
		M=vi(n,-1);
		ll res=0;
		while(augment(com)) res++;
		return res;
	}
	void preprocess(vector<vi> &com){
		com.resize(n,vi(n));
		used.clear(), M.clear(); vst.clear();
	}
	void add(ll a, ll b, vector<vi> &com){
		if(a>b) swap(a,b);
		if(used.count(mp(a,b))) return;
		used.insert(mp(a,b));
		com[a][b]=com[b][a]=1;
	}
} eb;
