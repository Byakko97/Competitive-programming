ll pp1[N];
ull pp2[N];

void prec(){
	pp1[0]=pp2[0]=1;
	For(i,1,N){
		pp1[i]=(pp1[i-1]*p)%MOD;
		pp2[i]=pp2[i-1]*p;
	}
}

struct Hsh{
	ll pref[N];
	ull pref2[N];
	void compute(string s){
		s = '#' + s;
		pref[0]=pref2[0]=0;
		For(i,1,sz(s)){
			pref[i] = (pref[i-1]*p+s[i]-'a')%MOD;
			pref2[i]= pref2[i-1]*p+s[i]-'a';
		}
	}
	pair<ll, ull> get(int l, int r){ 
		return mp((pref[r+1]-(pref[l]*pp1[r-l+1])%MOD+MOD)%MOD,pref2[r+1]-pref2[l]*pp2[r-l+1]);
	}
};
