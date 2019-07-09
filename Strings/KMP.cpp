int k=0;
rep(i, 1, n){
	while(k>0 && s[i]!=s[k]) k=pi[k-1];
	if(s[i]==s[k]) k++;
	pi[i]=k;
}
