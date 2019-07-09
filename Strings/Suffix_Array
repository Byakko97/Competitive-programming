string s;
int SA[N], tempSA[N], RA[N], tempRA[N];
int n;

void csort(int k){
	int maxi = max(300,n);
	int c[maxi]={0};
	rep(i,0,n) 
		c[i+k<n ? RA[i+k]:0]++;
	rep(i,1,maxi)
		c[i]+=c[i-1];
	rip(i,n-1,0)
		tempSA[--c[SA[i]+k<n ? RA[SA[i]+k]:0]]=SA[i];
	rep(i,0,n)
		SA[i]=tempSA[i];
}

void build(){
	rep(i,0,n){
		RA[i]=s[i];
		SA[i]=i;
	}
	for(int k=1; k<n; k<<=1){
		csort(k);
		csort(0);
		int r = tempRA[SA[0]]=0;
		rep(i,1,n)
			tempRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])? r:++r;
		rep(i,0,n)
			RA[i]=tempRA[i];
		if(r==n-1) break;		
	}
}
