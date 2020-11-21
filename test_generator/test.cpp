#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n=1e5,q=1e6;
	cout<<n<<" "<<q<<"\n";
	for(int i=1;i<=n;i++)	cout<<i<<" ";
	cout<<'\n';

	for(int itr=0;itr<5;itr++){
		int i=0,k=n;
		for(;i<n-1;i++,k--){
			cout<<1<<" "<<i<<" "<<k<<"\n";
		}	
		cout<<2<<"\n";
		i=0;k=1;
		for(;i<n-1;i++,k++){
			cout<<1<<" "<<i<<" "<<k<<"\n";
		}
		cout<<2<<"\n";
	}
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        // freopen("input.txt","r",stdin);
        freopen("test3.txt","w",stdout); 
    #endif
    solve();
}