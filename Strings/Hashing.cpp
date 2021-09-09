const ll MOD = 1e9+7;
const ll K = 2;
const ll P[K] = {29, 31};

array<ll, K> pot[N];
 
void prec() {
	For(k,0,K) pot[0][k] = 1;
	For(i,1,N)
		For(k,0,K)
			pot[i][k] = mul(pot[i-1][k], P[k]);
}
 
struct Hsh{
	array<ll, K> suf[N];
	void init(string &s) {
		roF(i,sz(s)-1,0)
			For(k,0,K)
				suf[i][k] = sum(mul(suf[i+1][k], P[k]), s[i] - 'a' + 1);
	}
	array<ll, K> que(int l, int r) {
		array<ll, K> cur;
		For(k,0,K)
			cur[k] = sum(suf[l][k], MOD - mul(suf[r][k], pot[r-l][k]));
		return cur;
	}
} hsh;
