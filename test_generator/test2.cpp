#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
	arr: 1 2 3 ... 1e5
	queries: 
	1 0 1e5
	2
	1 0 1
	2

	1 1 1e5-1
	2
	1 1 2
	2
	.
	.
	1 1e5/4-1 {}
	2
	1 1e5/4-1 {}
	2 
*/

void solve(){
	int n=1e5,qsets=(int)1e5/4;
	cout<<n<<" "<<n<<"\n";
	for(int i=1;i<=n;i++)	cout<<i<<" ";
	cout<<'\n';
	for(int i=1,upd1=1e5,upd2=1,indx=0;i<=qsets;i++,upd1--, upd2++,indx++){
		cout<<1<<" "<<indx<<" "<<upd1<<"\n";
		cout<<2<<"\n";
		cout<<1<<" "<<indx<<" "<<upd2<<"\n";
		cout<<2<<"\n";
	}
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        // freopen("input.txt","r",stdin);
        freopen("test2.txt","w",stdout); 
    #endif
    solve();
}