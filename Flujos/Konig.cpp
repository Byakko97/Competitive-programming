//grafo bipartido (X,Y) con |X|=n y |Y|=m

vi g[N]; //aristas de X a Y
int mat[M];
bool vis[N];

int n, m;

int match(int x){
	if(vis[x]) return 0;
	vis[x]=true;
	for(int y: g[x]) if(mat[y]<0 || match(mat[y])){
		mat[y]=x;
		return 1;
	}
	return 0;
}

vii max_matching(){
	vii r;
	For(i,0,m) mat[i]=-1;
	For(i,0,n){
		For(j,0,n) vis[j]=0;
		match(i);
	}
	For(i,0,m) if(mat[i]>=0) r.pb(mp(mat[i],i));
	return r;
}
