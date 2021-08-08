const int N=2e5+5;

ll table[N][20];

void buildtable(vector<ll> &a,int n){
	for(int i=0;i<n;i++){
			table[i][0]=a[i];		
	}
	for(int j=1;j<=19;j++){
		for(int i=0;i<=n-(1<<j);i++){
			table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
		}
	}
}

ll query(int L,int R){
	// int d=r-l+1;
	ll ans=0;
	for(int j = 19; j >= 0; j--) {
            if(L + (1 << j) - 1 <= R) {
                ans = __gcd(ans ,table[L][j]);
                L += 1 << j; // instead of having L', we increment L directly
            }
        }
	return ans;
}
