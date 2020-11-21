#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
	arr: 1e5 1e5 1e5 ... 1e5
	queries: 
	1 0 1e5
	1 1 1e5-1
	1 2 1e5-2
	.
	.
	.
	1 99998 2
	.
	.
	1 0 1e5
	1 1 1e5-1
	1 2 1e5-2
	.
	.
	.
	1 99998 2
	... (10 times)
	2
*/

void solve(){
	int n=1e6;
	cout<<n<<" "<<n<<"\n";
	for(int i=1;i<=n;i++)	cout<<1e5<<" ";
	cout<<'\n';
	int i=0,k=1;
	for(;i<n-1;i++,k++){
		cout<<1<<" "<<i<<" "<<k<<"\n";
		if(k==1e5+1)	k=1;
	}
	cout<<2<<"\n";
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        // freopen("input.txt","r",stdin);
        freopen("test4.txt","w",stdout); 
    #endif
    solve();
}
