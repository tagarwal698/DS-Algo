#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ff 					first
#define ss 					second
#define int 				long long
#define ll					long long int
#define pb 					push_back
#define mp 					make_pair
#define pii					pair<int,int>
#define vi					vector<int>
#define mii					map<int,int>
#define pqb					priority_queue<int>
#define pqs					priority_queue<int,vi,greater<int>>
#define setbits(x)			__builtin_popcountll(x) //number of setbits
#define zrobits(x)			__builtin_ctzll(x) //number of zeros before 1 from the right
#define mod					1000000007
#define inf					1e18
#define ps(x,y)				fixed<<setprecision(y)<<x //converts x upto y decimal places
#define mk(arr,n,type)		type *arr=new type[n];
#define w(t)				int t; cin>>t; while(t--)
mt19937						rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr,arr+n,rng)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
    	c_p_c();
	w(t){
	    int n,x,k;
	    cin >> n >> x >> k;
	    int t1 = 0, t2=n+1, count = 0, m=1;
	    int arr[n+2];
	    for(int i = 0; i < n+2; i++)  arr[i] = i;
	        while(t1<n+2){
	            if(t1==x){    count = 1; break; }
	            t1=t1+k;
	        }
	        while(t2>0){
	            if(t2==x){ count = 1; break;}
	            t2= n+1-(m*k); m++;
	        }
            if(count==1) cout<<"YES"<<endl;
            else cout << "NO" << endl;
	        
	    
	}

}