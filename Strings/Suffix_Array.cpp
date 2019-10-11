string s;
int SA[N], tempSA[N], RA[N], tempRA[N];
int phi[N], lcp[N], plcp[N];
int n;
int c[N];

void csort(int k){
	int maxi = max(300,n);
	For(i,0,maxi)
		c[i]=0;
	For(i,0,n) 
		c[i+k<n ? RA[i+k]:0]++;
	For(i,1,maxi)
		c[i]+=c[i-1];
	roF(i,n-1,0)
		tempSA[--c[SA[i]+k<n ? RA[SA[i]+k]:0]]=SA[i];
	For(i,0,n)
		SA[i]=tempSA[i];
}

void build(){
	For(i,0,n){
		RA[i]=s[i];
		SA[i]=i;
	}
	for(int k=1; k<n; k<<=1){
		csort(k);
		csort(0);
		int r = tempRA[SA[0]]=0;
		For(i,1,n)
			tempRA[SA[i]] = (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])? r:++r;
		For(i,0,n)
			RA[i]=tempRA[i];
		if(r==n-1) break;		
	}
}

void go(){
	int k=0;
	phi[SA[0]]=-1;
	For(i,1,n)
		phi[SA[i]] = SA[i-1];
	For(i,0,n-1){
		if(phi[i]==-1){
			plcp[i]=0;
			continue;
		}
		while(s[i+k]==s[phi[i]+k]) k++;
		plcp[i]=k;
		k=max(k-1,0);		
	}
	For(i,0,n)
		lcp[i]=plcp[SA[i]];
}
