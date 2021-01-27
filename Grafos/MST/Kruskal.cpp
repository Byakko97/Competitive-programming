	/*Implementar con Union Find*/
vector < pair<int, ii > > E;

rep(i,0,n){
	cin>>u>>v>>w;
	E.pb(mp(w, mp(u, v)));
}
sort(all(E));

int cost=0;
int cantEdge=0;
for(auto e: E){
	w=e.fst;
	u=e.snd.fst;
	v=e.snd.snd;
	if(find(u)!=find(v)){
		uni(u, v);
		costFin+=w;
		cantEdge++;
	}
	if(cantEdge==(n-1)) break;
}
