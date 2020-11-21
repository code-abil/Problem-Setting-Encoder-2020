#include<bits/stdc++.h>
#define ll long long
using namespace std;
using namespace std::chrono;

const int MAX_A=1e5, N=1e5;
vector<int>divisors[MAX_A+5];
int a[N+5],divCount[MAX_A+5];
set<int>gcds;

void pre_process(){
	for(int i=1;i<=MAX_A;i++){
		for(int j=i;j<=MAX_A;j+=i){
			divisors[j].push_back(i);
		}	
	}
}

void add(int data){
	for(auto x:divisors[data]){
		divCount[x]++;
		if(divCount[x]==2){
			gcds.insert(x);
		}
	}
}

void remove(int data){
	for(auto x:divisors[data]){
		divCount[x]--;
		if(divCount[x]==1){
			gcds.erase(x);
		}
	}
}

void solve(){
	pre_process();
	int n,q;cin>>n>>q;
	for(int i=0;i<n;i++)	cin>>a[i],add(a[i]);
	while(q--){
		int type;cin>>type;
		if(type==1){
			int index,data;
			cin>>index>>data;
			remove(a[index]);
			a[index]=data;
			add(a[index]);
			continue;
		}
		cout<<(*gcds.rbegin())<<"\n";
	}
}

main(){
	// auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        freopen("test4.txt","r",stdin);
        freopen("output1.txt","w",stdout); 
    #endif
    solve();
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << "Time taken by program: "
    //      << duration.count() << " microseconds" << endl; 
}