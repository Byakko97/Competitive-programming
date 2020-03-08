Problema UVA-10245: The Closest Pairs Problem
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1186
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ll((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
#define roF(i,a,b) for(ll i = ll(a); i >= ll(b); i--)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ld,ld> ii;
typedef vector<ii> vii;

const ll N=1e4+5;
const ll INF = 1e8;
const ll EPS = 1e-9;
ii coord[N];
vii caja;

ld dist(ii a, ii b){
	return (a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss);
}

ld merge(int l, int m, int r, ld men, ld xm){
	int taml = m-l, tamr=r-m;
	ii p[taml+1];
	ii q[tamr+1];
	For(i,0,taml) p[i]=coord[i+l];
	For(i,0,tamr) q[i]=coord[i+m];
	p[taml].ss=q[tamr].ss=INF;
	int itl=0, itr=0;
	For(i,l,r){
		if(p[itl].ss<q[itr].ss)
			coord[i]=p[itl++];
		else
			coord[i]=q[itr++];
	}
	For(i,l,r) if(abs(xm-coord[i].ff)<men-EPS)
		caja.pb(coord[i]);
	For(i,0,sz(caja)-1)
		For(j,i+1,sz(caja)) if(abs(caja[i].ss-caja[j].ss)<men-EPS){
			men = min(men,dist(caja[i],caja[j]));
		}else break;
	caja.clear();
	return men;
}

ld go(int l, int r){
	if(l >= r-1) return INF;
	int m = (l+r)>>1;
	ld xm = coord[m].ff;
	ld curl = go(l,m);
	ld curr = go(m,r);
	ld cur = merge(l,m,r,min(curl,curr),xm);
	return cur;
}

int main(){
	fastio;
	int n;
	cout << fixed << setprecision(4);
	while(cin>>n){
		if(n==0) break;
		For(i,0,n){
			cin >> coord[i].ff >> coord[i].ss;
		}
		sort(coord,coord+n);
		long double ans = go(0,n);
		if(ans>=INF) cout << "INFINITY" << endl;
		else cout << sqrt(ans) << endl;
	}
	return 0;
}
