//Convex Hull Trick (Monótono)
//Usar de guía y razonar cada caso de forma independiente

deque<ii> CHT;

lli eval(lli x, ii line){
	return line.fst*x+line.snd;
}

long double inter(ii a, ii b){
	return ((b.snd-a.snd)*1.0)/(a.fst-b.fst);
}

lli que(lli x){
	while(sz(CHT)>=2 && eval(x, CHT.back()) <= eval(x, CHT[sz(CHT)-2])) CHT.pop_back();
	return eval(x, CHT.back());
}

void insert(ii line){
	while(sz(CHT)>=2 && inter(line, CHT.front()) >= inter(CHT[0], CHT[1])) CHT.pop_front();
	CHT.push_front(line);
}
