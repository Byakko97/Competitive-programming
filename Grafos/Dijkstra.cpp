priority_queue < ii, vii, greater<ii> >

void dijkstra(){
	rep(i, 0, n) distancia[i] = 1LL<<62;
	distancia[0] = 0;
	PQ.push(mp(0 ,0));
	while(!PQ.empty()){
		lli origen = PQ.top().snd;
		lli w = PQ.top().fst;
		PQ.pop();
		if(w > distancia[origen]) continue;
		for(auto e: adj[origen]){
			lli destino =  e.fst;
			lli cost = e.snd;
			if((cost + w) <distancia[destino]){
				distancia[destino] = cost + w;
				PQ.push(mp( distancia[destino], destino)); 
			}
		}
	}
}
