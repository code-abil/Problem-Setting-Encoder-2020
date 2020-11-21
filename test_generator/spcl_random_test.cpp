#include<bits/stdc++.h>
#define ll long long
using namespace std;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_rand(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(){
	int n=2,q=1e5;
	cout<<n<<" "<<q<<"\n";
	int a[2]={(int)1e5-1,(int)1e5};
	cout<<a[0]<<" "<<a[0]<<"\n";
	while(q--){
		// Change the limits for different types of test-case generation.
		int type=get_rand(1,1);
		if(type==1){
			int idx1=get_rand(0,n-1);
			int idx2=get_rand(0,n-1);
			cout<<1<<" "<<idx1<<" "<<a[idx2]<<"\n";
		}else{
			cout<<2<<"\n";
		}
	}
}

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        // freopen("input.txt","r",stdin);
        freopen("spcl_random_test1.txt","w",stdout); 
    #endif
    solve();
}