//Convex Hull Trick (Monótono)
//Usar de guía y razonar cada caso de forma independiente

deque<ii> CHT;

ll eval(ll x, ii line){
	return line.ff*x+line.ss;
}

long double inter(ii a, ii b){
	return ((b.ss-a.ss)*1.0)/(a.ff-b.ff);
}
//Caso de maximización con pendiente decreciente.
//También se puede forzar a la función a cumplir con este caso.
ll que(ll x){
	while(sz(CHT)>=2 && eval(x, CHT.back()) <= eval(x, CHT[sz(CHT)-2])) CHT.pop_back();
	return eval(x, CHT.back());
}

void insert(ii line){
	while(sz(CHT)>=2 && inter(line, CHT.front()) >= inter(CHT[0], CHT[1])) CHT.pop_front();
	CHT.push_front(line);
}
