//Ejemplo: Product Sum (https://codeforces.com/problemset/problem/631/E)

ll eval(ll x, ii line){
	return line.ff*x+line.ss;
}

ld inter(ii a, ii b){
	return ld(b.ss-a.ss)/(a.ff-b.ff);
}

deque<ii> lines;

//Maximizacion
ll que(ll x){
	lines.push_front(mp(0,-INF));
	lines.pb(mp(0,-INF));
	int lo = 0, hi=sz(lines)-2;
	while(lo+1<hi){
		ll mid = (lo+hi)>>1;
		if(eval(x,lines[mid+1])-eval(x,lines[mid]) > -EPS) lo=mid;
		else hi=mid;
	}
	ll ans = eval(x,lines[hi]);
	lines.pop_front();
	lines.pop_back();
	return ans;
}

//Maximizacion con pendiente creciente
void insert(ii nline){
	while(sz(lines)>=2 && inter(nline,lines[sz(lines)-2]) < inter(lines[sz(lines)-2],lines.back())+EPS)
		lines.pop_back();
	lines.pb(nline);
}

//Maximizacion con pendiente decreciente
void insert2(ii nline){
	while(sz(lines)>=2 && inter(nline,lines[sz(lines)-2]) > inter(lines[sz(lines)-2],lines.back())-EPS)
		lines.pop_back();
	lines.pb(nline);
}

ll A[N], acum[N];

int main(){
	fastio;
	int n; cin>>n;
	ll tot=0;
	For(i,1,n+1){
		cin>>A[i];
		tot += A[i]*i;
		acum[i]=A[i]+acum[i-1];
	}
	ll best = 0;
	For(i,1,n+1){
		insert(mp(i,-acum[i-1]));
		best = max(best,-A[i]*i+acum[i-1]+que(A[i]));
	}
	lines.clear();
	roF(i,n,1){
		insert2(mp(i,-acum[i]));
		best = max(best,-A[i]*i+acum[i]+que(A[i]));
	}
	cout << tot + best << endl;;
	return 0;
}

