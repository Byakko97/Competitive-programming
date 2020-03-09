bool colinear(ii a, ii b, ii c){
	return (b.ff-a.ff)*(c.ss-a.ss)==(c.ff-a.ff)*(b.ss-a.ss)
			&& min(a.ff,b.ff)<=c.ff && c.ff<=max(a.ff,b.ff);
}

bool izq(ii a, ii b, ii c){
	return (b.ff-a.ff)*(c.ss-a.ss)>(c.ff-a.ff)*(b.ss-a.ss);
}

bool inter(pair<ii, ii> a, pair<ii, ii> b){
	if(colinear(a.ff,a.ss,b.ff) || colinear(a.ff,a.ss,b.ss) || colinear(b.ff,b.ss,a.ff) || colinear(b.ff,b.ss,a.ss))
		return 1;
	return izq(a.ff,a.ss,b.ff)!=izq(a.ff,a.ss,b.ss) && izq(b.ff,b.ss,a.ff)!=izq(b.ff,b.ss,a.ss);
}
