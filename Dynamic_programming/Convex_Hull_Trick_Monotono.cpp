//Convex Hull Trick (Monótono)
//Usar de guía y razonar cada caso de forma independiente


ll eval(ll x, ii line){
	return line.ff*x + line.ss;
}

ld inter(ii a, ii b){
	return ld(b.ss-a.ss)/(a.ff-b.ff);
}

//Caso de maximizacion con pendiente creciente
//y consultas en x crecientes

struct CHT{
	deque<ii> lines;
	ll que(ll x){
		while(sz(lines)>=2 && eval(x,lines[0])<=eval(x,lines[1]))
			lines.pop_front();
		return eval(x,lines[0]);
	}
	void insert(ii nline){
		while(sz(lines)>=2 && inter(nline,lines[sz(lines)-2]) < inter(lines.back(),lines[sz(lines)-2])+EPS)
			lines.pop_back();
		//solo lines.push_back(nline); cuando no hay pendientes iguales
		if(sz(lines)==1 && lines.back().ff==nline.ff && lines.back().ss<nline.ss)
			lines.pop_back();
		if(lines.empty() || nline.ff!=lines.back().ff)
			lines.push_back(nline);
	}	
} cht[N];
