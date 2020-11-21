#include<bits/stdc++.h>
#define ll long long
using namespace std;
using namespace std::chrono;

const int MAX_A=1e5, N=1e5;
vector<int>divisors[MAX_A+5];
int a[N+5],divCount[MAX_A+5];
set<int>gcds;

void add(int data){
	for(int i=1;i<=sqrt(data);i++){
		if(data%i==0){
			divCount[i]++;
			if(divCount[i]==2)	gcds.insert(i);

			if(i!=(data/i)){
				divCount[data/i]++;
				if(divCount[data/i]==2)	gcds.insert(data/i);
			}
		}
	}
}

void remove(int data){
	for(int i=1;i<=sqrt(data);i++){
		if(data%i==0){
			divCount[i]--;
			if(divCount[i]==1)	gcds.erase(i);

			if(i!=(data/i)){
				divCount[data/i]--;
				if(divCount[data/i]==1)	gcds.erase(data/i);
			}
		}
	}
}

void solve(){
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