#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff                  first
#define ss                  second
#define ll                 long long
#define pb                  push_back
#define mp                  make_pair
#define pii                 pair<int,int>
#define vi                  vector<int>
#define mii                 map<int,int>
#define pqb                 priority_queue<int>
#define pqs                 priority_queue<int,vi,greater<int>>
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define mod                 1000000007
#define inf                 1e18
#define ps(x,y)             fixed<<setprecision(y)<<x;
#define mk                  type *arr=new type[n];
#define w(x)                int x; cin>>x; while(x--)
#define frl(i,a,b)			for(int i=a;i<b;i++)
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void tushaaaaarrrr(){
    ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
}

int32_t main(){
    void tushaaaaarrrr();

    int t;
	    cin>>t;
	    while(t--){
	        long long n,x;
	        cin >> n >> x;
	        set <long long> v;
	        for(int i=0;i<n;i++) {long long m; cin >> m; v.insert(m);}
			long long can = v.size();
			cout << min(n-x,can) << endl;
  
    }
    }

