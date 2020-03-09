//Ejemplo: The Door Problem http://codeforces.com/contest/776/problem/D

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
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll N=2e5+5;

vi adj[N];
vi adjt[N];
bool vis[N];
int comp[N];
stack<int> order;

void dfs(int v){
	vis[v]=1;
	for(int u:adj[v]) if(!vis[u])
		dfs(u);
	order.push(v);
}

void dfs2(int v, int cl){
	comp[v]=cl;
	for(int u:adjt[v]) if(comp[u]==-1)
		dfs2(u,cl);
}

bool r[N];
vi p[N];

int main(){
	fastio;
	int n, m; cin>>n>>m;
	For(i,0,n){
		cin>>r[i];
	}
	For(i,0,m){
		int x; cin>>x;
		For(j,0,x){
			int q; cin>>q; q--;
			p[q].pb(i<<1);
		}			
	}
	// Por cada p v q, agregar
	// adj[p^1].pb(q), adj[q^1].pb(p) y los transpuestos
	For(i,0,n){
		if(r[i]==0){
			adj[p[i][0]].pb(p[i][1]^1);
			adj[p[i][1]].pb(p[i][0]^1);
			adj[p[i][0]^1].pb(p[i][1]);
			adj[p[i][1]^1].pb(p[i][0]);
			adjt[p[i][0]].pb(p[i][1]^1);
			adjt[p[i][1]].pb(p[i][0]^1);
			adjt[p[i][0]^1].pb(p[i][1]);
			adjt[p[i][1]^1].pb(p[i][0]);
		}else{
			adj[p[i][0]].pb(p[i][1]);
			adj[p[i][1]].pb(p[i][0]);
			adj[p[i][0]^1].pb(p[i][1]^1);
			adj[p[i][1]^1].pb(p[i][0]^1);
			adjt[p[i][0]].pb(p[i][1]);
			adjt[p[i][1]].pb(p[i][0]);
			adjt[p[i][0]^1].pb(p[i][1]^1);
			adjt[p[i][1]^1].pb(p[i][0]^1);
		}
	}
	For(i,0,m){
		comp[i<<1]=comp[i<<1|1]=-1;
	}
	For(i,0,m<<1) if(!vis[i])
		dfs(i);
	int cl=0;
	For(i,0,m<<1){
		int v = order.top();
		order.pop();
		if(comp[v]==-1)
			dfs2(v, cl++);
	}
	For(i,0,m){
		if(comp[i<<1]==comp[i<<1|1]){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	return 0;
}

