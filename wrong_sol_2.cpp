#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n,q;cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int ans=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans=max(ans,__gcd(a[i],a[j]));
		}
	}
	while(q--){
		int type;cin>>type;
		if(type==1){
			int index,data;
			cin>>index>>data;
			a[index]=data;
			ans=1;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					ans=max(ans,__gcd(a[i],a[j]));
				}
			}
			continue;
		}
		cout<<ans<<"\n";
	}
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout); 
    #endif
    solve();
}