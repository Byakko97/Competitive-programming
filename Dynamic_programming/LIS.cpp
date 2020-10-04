vi aux;

int lis(vi& V){ 
	for(auto x: V){
		auto it = upper_bound(all(aux),x);
		if(it==aux.end()) aux.pb(x);
		else *it=x;
	}
	return sz(aux);
}
