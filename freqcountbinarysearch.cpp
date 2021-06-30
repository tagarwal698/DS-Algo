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
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {

/*sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);*/

template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
	~debug() { cerr << endl; }
	
	//eni(!=) cerr << boolalpha << i; ris; }        Part 1
	
	template < class c > typename \
	enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
		cerr << boolalpha << i;
		return * this;
	}
	
	//eni(==) ris << range(begin(i), end(i)); }     Part 2
	
	template < class c > typename \
	enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
		return * this << range(begin(i), end(i)); 
	}
	
	/*sim, class b dor(pair < b, c > d) {           Part 3
		ris << "(" << d.first << ", " << d.second << ")";
	}*/
	
	template < class c, class b > debug & operator << (pair < b, c > d) {
		return * this << "(" << d.first << ", " << d.second << ")";
	}
	
	/*sim dor(rge<c> d) {                           Part 4
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		ris << "]";
	}*/
	
	template < class c > debug & operator <<(rge<c> d) {
		*this << "[";
		for (auto it = d.b; it != d.e; ++it)
			*this << ", " + 2 * (it == d.b) << *it;
		return * this << "]";
	}
	
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void c_p_c(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    		freopen("input.txt", "r", stdin);
    		freopen("output.txt", "w", stdout);
#endif
}

int upperbound(vector <int> arr, int k){
	int n = arr.size();
	int s = 0;
	int e = arr.size() - 1;
	int ans = -1;
	// if(arr[mid]==k){ 
	// 	int ans = freq(arr,s,mid-1,k)
	// 	return ans;
	// }
	// else if(arr[mid]>k)	return freq(arr,s,mid-1, k);
	// else return freq(arr,mid+1,e,k);
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==k){
			ans = mid;
			s = mid+1;
		}
		else if(arr[mid]>k)	e = mid - 1;
		else s = mid + 1;
	}
	return ans;
}


int lowerbound(vector <int> arr, int k){
	int n = arr.size();
	int s = 0;
	int e = arr.size() - 1;
	int ans = -1;
	// if(arr[mid]==k){ 
	// 	int ans = freq(arr,s,mid-1,k)
	// 	return ans;
	// }
	// else if(arr[mid]>k)	return freq(arr,s,mid-1, k);
	// else return freq(arr,mid+1,e,k);
	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==k){
			ans = mid;
			e = mid-1;
		}
		else if(arr[mid]>k)	e = mid - 1;
		else s = mid + 1;
	}
	return ans;
}

int32_t main()
{
	c_p_c();
	vector <int> arr;
	int n;
	cin >> n;
	int k;
	cin >> k;
	int s = 0;
	int e = n-1;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp; arr.pb(temp);
	}
	auto lb = lowerbound(arr,k);
	auto ub = upperbound(arr,k);
	cout << ub-lb+1 << endl;
	//using STL (ONE LINE SOLUTION) 
	cout << upper_bound(arr.begin(),arr.end(),1) - lower_bound(arr.begin(),arr.end(),1) << endl;
}