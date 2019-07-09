lli A[N];
lli MX[N]; //MX[i] -> posición del último valor de secuencia de tamaño i
lli P[N]; //Padre de i

int lis=0;
rep(i,0,cant){
	int lo=1;
	int hi=lis;
	while(lo<=hi){
		int mid= ceil((lo+hi)/2);
		if(A[MX[mid]]<A[i]){ 
			lo=mid+1;
		}else{
			hi=mid-1;
		}
	}
	MX[lo]=i; //upper_bound
	P[i]=MX[lo-1];
	if(lo>lis) lis=lo;
}
