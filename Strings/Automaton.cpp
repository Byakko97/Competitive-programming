int go(int i, int j){
	if(kmp[i][j]!=-1) return kmp[i][j];
	int ans;
	if(t[i]==j+'a') ans=i+1;
	else if(i==0) ans=0;
	else ans=go(pi[i-1], j);
	return kmp[i][j]=ans;
}
