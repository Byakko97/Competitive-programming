dp[i][i+k] = min(i<=j<=i+k){dp[i][j]+dp[j][i+k]} + cost[i][i+k]

a<=b<=c<=d
cost[a][d]+cost[b][c] >= cost[a][c]+cost[b][d] && cost[b][c]<=cost[a][d]
	implica:	opt[i][i+k-1] <=  opt[i][i+k] <= opt[i+1][i+k]
	
Ejemplo (Break String):

/* Fairy dandy tickling the fancy of his lady friend */
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define rep(i,a,b) for(int i=int(a); i<int(b); i++)
#define rip(i,a,b) for(int i=(int)a; i>=(int)b; i--)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) int(x.size())
#define all(v) (v).begin(), (v).end()
#define trace(x) cerr << #x << ": " << x <<endl;

using namespace std;

typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;

vi V;
lli dp[1005][1005];
int opt[1005][1005];

int main(){
    fastio;
	lli n, m, a;
	while(cin>>n>>m){
		V.pb(0);
		rep(i, 0, m){
			cin>>a;
			V.pb(a);
		}
		V.pb(n);
		rep(k, 0, m+2)
			rep(i, 0, m+2-k){
				if(k<2){
					dp[i][i+k]=0;
					opt[i][i+k]=i;
					continue;
				}
				dp[i][i+k]=1LL<<62;
				rep(j, opt[i][i+k-1], opt[i+1][i+k]+1){
					lli cur = V[i+k]-V[i] + dp[i][j] + dp[j][i+k];
					if(cur<dp[i][i+k]){
						dp[i][i+k]=cur;
						opt[i][i+k]=j;
					}						
				}
			} 
		cout<<dp[0][m+1]<<endl;
		V.clear();
	}
    return 0;
}
