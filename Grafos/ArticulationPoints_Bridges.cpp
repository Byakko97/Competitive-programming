vi adj[N];
int p[N];
int disc[N];
int low[N];
bool vis[N];
int t;
int ans;
int child;
int root;
bool AP[N];
 
void DFS(int v){
	vis[v]=true;
	low[v]=disc[v]=t++;
 
	for(int u: adj[v]){
		if(!vis[u]){
			p[u]=v;
			if(v==root) child++;
			DFS(u);
			low[v]=min(low[v],low[u]);
			if(p[v]!=-1 && low[u]>=disc[v] && !AP[v]){ //Estrictamente mayor para Bridges
				AP[v]=true; //Guardar un par para Bridges
				ans++;
			}
		}else{
			if(u!=p[v]){
				low[v]=min(low[v], disc[u]);
			}
		}
	}
}

int main(){
	DFS(root);
	AP[root]= (child>1);
	return 0;
}
