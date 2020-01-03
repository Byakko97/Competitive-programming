//must include these libraries
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
//and this namespace
using namespace __gnu_pbds;

//template of tree
typedef tree<Key, Mapped, Comp, rb_tree_tag,
			tree_order_statistics_node_update> struct_name;
//Mapped can be null_type for sets

//added operations
*S.find_by_order(i); //i-th node Key ordered by Comp
S.order_of_key(key); //position of key as if it is in the tree

//Example: Optimal Subsequences (Hard version) http://codeforces.com/contest/1262/problem/D2 (ordered_set)

typedef tree<ii, null_type, less<ii>, rb_tree_tag,
			tree_order_statistics_node_update> ordered_set;
 
ordered_set S;
vii V;
vector<pair<ii, int> > Q;
 
ll ANS[N];
 
bool comp(ii a, ii b){
	return a.ff!=b.ff ? a.ff>b.ff : a.ss<b.ss;
}
 
int main(){
	fastio;
	cin>>n;
	For(i,0,n){
		ll x; cin>>x;
		V.pb(mp(x,i));
	}
	cin>>m;
	For(i,0,m){
		ll k, j; cin>>k>>j;
		Q.pb(mp(mp(k,j),i));
	}
	sort(all(Q));
	sort(all(V), comp);
	int i=0;
	for(auto q : Q){
		while(i<q.ff.ff){
			S.insert(mp(V[i].ss, V[i].ff));
			i++;
		}
		ANS[q.ss]=(*S.find_by_order(q.ff.ss-1)).ss;
	}
	For(i,0,m)
		cout<<ANS[i]<<endl;
	return 0;
}
