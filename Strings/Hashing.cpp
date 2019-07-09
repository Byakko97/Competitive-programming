lli pref[N], pp1[N];
ull pref2[N], pp2[N];

void prec(){
	pp1[0]=pp2[0]=1;
	rep(i,1,N){
		pp1[i]=(pp1[i-1]*p)%MOD;
		pp2[i]=pp2[i-1]*p;
	}
}

void calc(){
	s='#'+s;
	pref[0]=0;
	pref2[0]=0;
	rep(i,1,n+1){
		pref[i]=(pref[i-1]*p+s[i]-'a')%MOD;
		pref2[i]=pref2[i-1]*p+s[i]-'a';
	}
}

pair<lli, ull> conv(int l, int r){
	return mp((pref[r]-(pref[l-1]*pp1[r-l+1])%MOD + MOD)%MOD, pref2[r]-pref2[l-1]*pp2[r-l+1]);
}
