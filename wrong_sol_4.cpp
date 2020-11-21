#include<bits/stdc++.h>
#define ll long long
using namespace std;
using namespace std::chrono;

const int MAX_A=1e5, N=1e5;
vector<int>divisors[MAX_A+5];
int a[N+5],seg[4*MAX_A+5];

void pre_process(){
	for(int i=1;i<=MAX_A;i++){
		for(int j=i;j<=MAX_A;j+=i){
			divisors[j].push_back(i);
		}	
	}
}

void update(int index,int data,int segindex,int l,int r)
{
    if(l==r){
        seg[segindex]+=data;
        return ;
    }
    int mid=(l+r)/2;
    if(index<=mid)	update(index,data,2*segindex+1,l,mid);
    else			update(index,data,2*segindex+2,mid+1,r);
    seg[segindex]=max(seg[2*segindex+1],seg[2*segindex+2]);
}

int query(int index,int l,int r)
{
	if(l==r)	return l;
	int mid=(l+r)/2;
	if(seg[2*index+2]>1){
		return query(2*index+2,mid+1,r);
	}else{
		return query(2*index+1,l,mid);
	}
}

void add(int data){
	for(auto x:divisors[data]){
		update(x,1,0,0,MAX_A);
	}
}

void remove(int data){
	for(auto x:divisors[data]){
		update(x,-1,0,0,MAX_A);
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

		cout<<query(0,0,MAX_A)<<"\n";
	}
}

main(){
	// auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    #ifndef ONLINE_JUDGE    
        freopen("test3.txt","r",stdin);
        freopen("output1.txt","w",stdout); 
    #endif
    solve();
    // auto stop = high_resolution_clock::now(); 
    // auto duration = duration_cast<microseconds>(stop - start); 
    // cout << "Time taken by program: "
    //      << duration.count() << " microseconds" << endl; 
}