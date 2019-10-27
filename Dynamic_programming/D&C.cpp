dp[i][j] = min(0<=k<j){dp[i-1][k]+cost[k][j]}

opt[i][j]<=opt[i][j+1] (Probar por el absurdo)
	
void go(int k, int l, int r, int optl, int optr){
	if(l>r) return;
	int opt, m = (l+r)>>1;
	For(i, optl, min(m, optr+1)){
		ll cur = dp[i][k-1] + cost(i, m);
		if(cur<dp[m][k]){
			dp[m][k]=cur;
			opt=i;
		}
	}
	go(k, l, m-1, optl, opt);
	go(k, m+1, r, opt, optr);
}

int main(){
	For(i, 0, L+1) For(j, 0, G+1) dp[i][j]=1LL<<62;
	For(i, 1, L+1) dp[i][1]=C[i]*i; //caso base
	For(i, 2, G+1) go(i, i, L, i-1, L-1); 
	cout<<dp[L][G]<<endl;
	return 0;
}
