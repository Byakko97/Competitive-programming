//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N=1e6;
const int MOD = 1e9+7;

void mul(ll a[5][5], ll  b[5][5], ll  c[5][5]){
	For(i,0,5)
		For(j,0,5){
			c[i][j]=0;
			For(k,0,5)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
		}
}

ll binpow(ll mat[5][5], ll p, ll ans[5][5]){
	ll temp[5][5];
	while(p){
		if(p&1){
			mul(ans, mat, temp);
			For(i,0,5) For(j,0,5) ans[i][j]=temp[i][j];
		}
		mul(mat, mat, temp);
		For(i,0,5) For(j,0,5) mat[i][j]=temp[i][j];
		p>>=1;
	}
}

ll go(ll n){
	if(n<0) return 0;
	n/=10;
	ll mat[5][5]={ {16, 9, 4, 1, 0},
					{1, 0, 0, 0, 0},
					{0, 1, 0, 0, 0},
					{0, 0, 1, 0, 0},
					{0, 0, 0, 1, 1} };
	ll ans[5][5] = {0};
	For(i,0,5) ans[i][i]=1;
	binpow(mat, n, ans);
	ll res=0;
	For(i,0,5) res = (res+ans[i][0])%MOD;
	//For(i,0,5) trace(ans[i][0]);
	return res;
}

int main(){
	fastio;
	ll n; cin>>n;
	ll tot = go(n);
	ll death = go(n-45);
	cout<< (tot-death+MOD)%MOD << endl;
	return 0;
}
