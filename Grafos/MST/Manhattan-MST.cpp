//tomada de https://ei1333.github.io/library/graph/mst/manhattan-mst.cpp.html
//Aplicar Kruskal sobre las aristas resultantes
vector<pair<ll, ii> > E;

void manhattan_mst(vi xs, vi ys){
	int n = sz(xs);
	vi ord(n);
	For(i,0,n) ord[i]=i;
	For(s,0,2){
		For(t,0,2){
			auto cmp = [&](int i, int j) -> bool{
				if(xs[i]+ys[i] == xs[j]+ys[j]) return ys[i]<ys[j];
				return xs[i]+ys[i] < xs[j]+ys[j];
			};
			sort(all(ord),cmp);
			map<int, int> id;
			for(int i: ord){
				for(auto it = id.lower_bound(-ys[i]); it!=id.end(); it = id.erase(it)){
					int j = it->ss;
					if(xs[j]-ys[j] > xs[i]-ys[i]) break;
					E.pb(mp(abs(xs[i]-xs[j])+abs(ys[i]-ys[j]),mp(i,j)));
				}
				id[-ys[i]] = i;
			}
			swap(xs,ys);
		}
		For(i,0,n) xs[i] *= -1;
	}
}
