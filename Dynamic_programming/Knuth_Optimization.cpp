dp[i][i+k] = min(i<=j<=i+k){dp[i][j]+dp[j][i+k]} + cost[i][i+k]

a<=b<=c<=d
cost[a][d]+cost[b][c] >= cost[a][c]+cost[b][d] && cost[b][c]<=cost[a][d]
	implica:	opt[i][i+k-1] <=  opt[i][i+k] <= opt[i+1][i+k]

For(k, 0, m)
	For(i, 0, m-k){
		if(k<2){
			dp[i][i+k]=0;
			opt[i][i+k]=i;
			continue;
		}
		dp[i][i+k]=1LL<<62;
		For(j, opt[i][i+k-1], opt[i+1][i+k]+1){
			ll cur = costo[i][i+k] + dp[i][j] + dp[j][i+k];
			if(cur<dp[i][i+k]){
				dp[i][i+k]=cur;
				opt[i][i+k]=j;
			}						
		}
	} 
V.clear();
	
