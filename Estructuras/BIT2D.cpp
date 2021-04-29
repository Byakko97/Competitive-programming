//add in position, query of sum in rectangle

ll bit[N][N];
int n;

void upd(int x, int y, ll d){
	for(int i=x; i<n; i = i | (i+1))
		for(int j = y; j<n; j = j|(j+1))
			bit[i][j]+=d;
}

ll que(int x, int y){
	ll ans = 0;
	for(int i = x; i>=0; i = (i&(i+1))-1)
		for(int j = y; j>=0; j = (j&(j+1))-1)
			ans += bit[i][j];
	return ans;
}

ll A[N][N];

int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		char s[4];
		while(1){
			scanf("%s",s);
			if(s[2]=='T'){
				int x, y;
				ll num;
				scanf("%d%d%lld",&x, &y, &num);
				upd(x,y,-A[x][y]);
				A[x][y]=num;
				upd(x,y,A[x][y]);
			}else if(s[2]=='M'){
				int x1, y1, x2, y2; scanf("%d%d%d%d",&x1, &y1, &x2, &y2);
				printf("%lld\n", que(x2,y2) - que(x2,y1-1) - que(x1-1,y2) + que(x1-1,y1-1));
			}else break;
		}
		For(i,0,n) For(j,0,n) upd(i,j,-A[i][j]), A[i][j]=0;
		printf("\n");
	}
	return 0;
}
