dp[i][j] = min(0<=k<j){dp[i-1][k]+cost[k][j]}

opt[i][j]<=opt[i][j+1] (Probar por el absurdo)

Ejemplo(Guardians of the Lunatics):

int L;
lli dp[8005][805];
lli C[8005];

lli cost(lli i, lli j){
	return (j-i)*(C[j]-C[i]);
}

void go(int k, int l, int r, int optl, int optr){
	if(l>r) return;
	int opt;
	int m = (l+r)>>1;
	rep(i, optl, min(m, optr+1)){
		lli cur = dp[i][k-1] + cost(i, m);
		if(cur<dp[m][k]){
			dp[m][k]=cur;
			opt=i;
		}
	}
	go(k, l, m-1, optl, opt);
	go(k, m+1, r, opt, optr);
}

int main(){
	fastio;
	int G; cin>>L>>G;
	G = min(L, G);
	lli c;
	rep(i, 1, L+1){
		cin>>c;
		C[i]=C[i-1]+c;
	}
	rep(i, 0, L+1) rep(j, 0, G+1) dp[i][j]=1LL<<62;
	rep(i, 1, L+1) dp[i][1]=C[i]*i;
	rep(i, 2, G+1) go(i, i, L, i-1, L-1); 
	cout<<dp[L][G]<<endl;
	return 0;
}
