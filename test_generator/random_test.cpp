#include<bits/stdc++.h>
#define ll long long
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n=1000,q=1e5;
	cout<<n<<" "<<q<<"\n";
	for(int i=1;i<=n;i++){
		cout<<i<<" ";
	}
	cout<<"\n";
	while(q--){
		int type=get_rand(1,2);
		if(type==1){
			int idx=get_rand(0,n-1);
			int upper_bound=get_rand(1,1e3);
			int data=get_rand(1,upper_bound);
			cout<<1<<" "<<idx<<" "<<data<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        // freopen("input.txt","r",stdin);
        freopen("random_test1.txt","w",stdout); 
    #endif
    solve();
}